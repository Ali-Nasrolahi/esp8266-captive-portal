/**
 * @file config.h
 * @author Ali Nasrolahi (a.nasrolahi01@gmail.com)
 * @brief Configuration macros.
 * @date 2023-03-31
 */
#ifndef _CONFIG_H_
#define _CONFIG_H_

/* Configuration settings */
#define BAUDRATE 115200
#define WIFI_SSID "FREE WIFI"
#define AP_IPADDR (172, 0, 0, 1)
#define AP_SUBNET (255, 255, 255, 0)
#define AP_CHANNEL 14
#define HIDDEN_AP 1

/**
 * @brief Using LittleFS for loading webpages or hard-coded data (default).
 * @warning LittleFS structure and Webpage's data must be flashed manually.
 */
#define USE_FS 0

/* HTTP Macros */
#define HTTP_SUCCESS 200

/* HTTP Content types*/
#define HTTP_PLAIN "text/plain"
#define HTTP_HTML "text/html"
#define HTTP_CSS "text/css"
#define HTTP_APP_JS "application/javascript"
#define HTTP_IMG_JPG "image/JPG"

#endif
