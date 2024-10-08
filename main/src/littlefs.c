#include "littlefs.h"

#define TAG "littlefs"

esp_vfs_littlefs_conf_t littlefs_conf;

void littlefs_init(esp_vfs_littlefs_conf_t *conf)
{
    ESP_LOGI(TAG, "Initializing LittleFS");

    conf->base_path = "/littlefs";
    conf->partition_label = "storage";
    conf->format_if_mount_failed = true;
    conf->dont_mount = false;

    // 配置结构体以初始化并挂载littlefs文件系统
    // NOTE: esp_vfs_littlefs_register 函数将多个挂载步骤整合至该接口中
    esp_err_t ret = esp_vfs_littlefs_register(conf);

    if (ret != ESP_OK) 
    {
        if (ret == ESP_FAIL) 
        {
            ESP_LOGE(TAG, "Failed to mount or format filesystem");
        } 
        else if (ret == ESP_ERR_NOT_FOUND) 
        {
            ESP_LOGE(TAG, "Failed to find LittleFS partition");
        } 
        else 
        {
            ESP_LOGE(TAG, "Failed to initialize LittleFS (%s)", esp_err_to_name(ret));
        }
        return;
    }    
}

void get_littlefs_stat(esp_vfs_littlefs_conf_t *conf)
{
    size_t total = 0, used = 0;
    esp_err_t ret = esp_littlefs_info(conf->partition_label, &total, &used);
    if (ret != ESP_OK) 
    {
        ESP_LOGE(TAG, "Failed to get LittleFS partition information (%s)", esp_err_to_name(ret));
        esp_littlefs_format(conf->partition_label);
    } 
    else 
    {
        ESP_LOGI(TAG, "Partition size: total: %d, used: %d", total, used);
    }
}