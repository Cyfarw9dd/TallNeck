#include "get_tle.h"

#define TAG         "get_tle"

esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    static char *output_buffer;  // 用于存储HTTP请求响应的缓冲区
    static int output_len;       // 存储已读取的字节数
    switch(evt->event_id) {
        // HTTP_EVENT_ON_DATA事件在接收到HTTP响应的数据时触发，它可能会被多次触发，每次接受到一部分数据的时候都会执行
        case HTTP_EVENT_ON_DATA:
            if (!esp_http_client_is_chunked_response(evt->client)) {
                // 如果配置了user_data缓冲区，将响应复制到缓冲区
                if (evt->user_data) {
                    memcpy(evt->user_data + output_len, evt->data, evt->data_len);
                } else {
                    if (output_buffer == NULL) {
                        output_buffer = (char *) malloc(esp_http_client_get_content_length(evt->client));
                        output_len = 0;
                        if (output_buffer == NULL) {
                            ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                            return ESP_FAIL;
                        }
                    }
                    memcpy(output_buffer + output_len, evt->data, evt->data_len);
                }
                output_len += evt->data_len;
            }
            break;
        // HTTP_EVENT_ON_FINISH事件
        case HTTP_EVENT_ON_FINISH:
            if (output_buffer != NULL) {
                // 在这里处理完整的响应数据，例如写入文件
                FILE* f = fopen(FILE_PATH, "w");
                if (f == NULL) {
                    ESP_LOGE(TAG, "Failed to open file for writing");
                } else {
                    ESP_LOGI(TAG, "Writing data to the file.\n");
                    fprintf(f, "%s", output_buffer);
                    fclose(f);
                }
                free(output_buffer);
                output_buffer = NULL;
            }
            output_len = 0;
            break;
        default:
            break;
    }
    return ESP_OK;
}

void download_tle_task(void *pvParameters)
{
    ESP_LOGI(TAG, "Downloading TLE data from URL");

    esp_http_client_config_t config = {
        .url = ISS_URL,  // 页面URL
        /**
         * @brief   如果是普通的HTTP连接，那么是不需要配置证书的，而HTTPS需要
         */
        .cert_pem = NULL,  // 用于配置指定服务器的SSL证书，NULL代表使用默认证书
        .skip_cert_common_name_check = true,  // 跳过证书通用名称的检查
        .transport_type = HTTP_TRANSPORT_OVER_SSL,  // 确保客户端和服务器端的通信是加密的，指定使用SSL/TLS加密的HTTP连接
        /**
         * @brief   esp_crt_bundle_attach 是 ESP-IDF 提供的一个函数，它会加载一个包含多个受信任 CA 证书的捆绑包。
         *          这样可以验证各种不同的服务器证书，而不需要单独指定每个证书。
         */
        .crt_bundle_attach = esp_crt_bundle_attach,  
        .event_handler = _http_event_handler,  // 定义事件处理函数
    };
    
    esp_http_client_handle_t client = esp_http_client_init(&config);
    esp_http_client_set_method(client, HTTP_METHOD_GET);
    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "HTTP GET Status = %d, content_length = %lld",
                 esp_http_client_get_status_code(client),
                 esp_http_client_get_content_length(client));

        // 在这里对下载的数据进行检验
        FILE *fp = fopen(FILE_PATH, "r");
        ESP_LOGI(TAG, "After downloading the file, the content is:\n");
        char temp_buffer[128];
        while (fgets(temp_buffer, sizeof(temp_buffer), fp))
        {
            ESP_LOGW(TAG, "%s", temp_buffer);
        }
        fclose(fp);
        ESP_LOGI(TAG, "File checked successfully");
    } 
    else 
    {
        ESP_LOGE(TAG, "HTTP GET request failed: %s", esp_err_to_name(err));
    }

    esp_http_client_cleanup(client);
    vTaskDelete(NULL);
}


