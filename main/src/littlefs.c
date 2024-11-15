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

void get_file_info(void)
{
    FILE *tle = fopen(FILE_PATH, "r");
    FILE *time = fopen(LATEST_TIME_PATH, "r");
    if (NULL == tle)
    {
        ESP_LOGE(TAG, "Failed to open the TLE file.\n");
        fclose(tle);
        return;
    }
    if (NULL == time)
    {
        ESP_LOGE(TAG, "Failed to open the TIME file.\n");
        fclose(tle);
        fclose(time);
    }
    char buffer[256];
    printf("TLE file: \n");
    while (fgets(buffer, sizeof(buffer), tle))
    {
        printf("%s", buffer);
    }
    printf("Latest time file: \n");
    while (fgets(buffer, sizeof(buffer), time))
    {
        printf("%s", buffer);
    }
    fclose(tle);
    fclose(time);
}

void sync_latest_time(void)
{
    char latest_time[128];

    // 下载结束之后同步当前时间并记录
    sntp_netif_sync_time();  
    struct timeval tv;
    struct tm time;

    gettimeofday(&tv, NULL);
    localtime_r(&tv.tv_sec, &time);
    sprintf(latest_time, "%d.%d.%d %d:%d:%d\n", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);

    FILE *fp = fopen(LATEST_TIME_PATH, "w");
    if (NULL == fp)
    {
        ESP_LOGE(TAG, "Failed to open the latest time file.\n");
        fclose(fp);
        return;
    }
    fprintf(fp, "%s", latest_time);
    printf("Latest update time: %s\n", latest_time);

    fclose(fp);
}