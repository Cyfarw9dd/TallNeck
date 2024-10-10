#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/timers.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"

#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#include "esp_system.h"
#include "esp_task_wdt.h"
#include "esp_littlefs.h"
#include "esp_http_client.h"
#include "http_app.h"
#include "esp_crt_bundle.h"

#include "wifi_manager.h"
#include "littlefs.h"

#define ISS_URL                 "https://celestrak.org/NORAD/elements/gp.php?CATNR=25544&FORMAT=tle"
#define AMATEUR_URL             "https://celestrak.org/NORAD/elements/gp.php?GROUP=amateur&FORMAT=tle"
#define FILE_PATH               "/littlefs/ISS(ZARYA).txt"
#define WIFI_CONNECTED_BIT      BIT0

esp_err_t _http_event_handler(esp_http_client_event_t *evt);

void download_tle_task(void *pvParameters);

