/**
 * @file esp8266_captive_portal.ino
 * @author Ali Nasrolahi (a.nasrolahi01@gmail.com)
 * @brief captive portal implementation using esp8266 chip.
 * @date 2023-03-31
 *
 */
#include "include/webpage.hpp"

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

unsigned long lastTick;

DNSServer dnsServer;
ESP8266WebServer webServer(SERVER_PORT);
Webpage webpage(&webServer);
IPAddress AP_ADDR AP_IPADDR;

void setup()
{
    Serial.begin(BAUDRATE);

    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(AP_ADDR, AP_ADDR, IPAddress(255, 255, 255, 0));
    dnsServer.start(DNS_PORT, "*", AP_ADDR);

    WiFi.softAP(WIFI_SSID, "", AP_CHANNEL, HIDDEN_AP);
    delay(500);

    webServer.on("/", []() { webpage.index(); });
    webServer.on("/index", []() { webpage.index(); });
    webServer.on("/style.css", []() { webpage.style(); });
    webServer.on("/background.jpg", []() { webpage.background(); });
    webServer.on("/post", []() { webpage.postHandler(); });
    webServer.on("/show", []() { webpage.showData(); });

    webServer.onNotFound([]() { webpage.index(); });

    webServer.begin();
}

void loop()
{
    if ((millis() - lastTick) > 1000) {
        lastTick = millis();
    }

    dnsServer.processNextRequest();
    webServer.handleClient();
}
