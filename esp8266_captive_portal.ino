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

const byte DNS_PORT = 53;
IPAddress AP_ADDR AP_IPADDR;

unsigned long lastActivity, lastTick;

DNSServer dnsServer;
ESP8266WebServer webServer(80);
Webpage webpage(&webServer);

void BLINK()
{
    for (int counter = 0; counter < 10; counter++) {
        digitalWrite(BUILTIN_LED, counter % 2);
        delay(500);
    }
}

void setup()
{
    Serial.begin(BAUDRATE);

    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(AP_ADDR, AP_ADDR, IPAddress(255, 255, 255, 0));
    dnsServer.start(DNS_PORT, "*", AP_ADDR);

    Serial.println("Setting AP ssid: " WIFI_SSID ".");
    WiFi.softAP(WIFI_SSID, "", AP_CHANNEL, HIDDEN_AP);
    delay(500);

    webServer.on("/", []() { webpage.index(); });
    webServer.on("/index", []() { webpage.index(); });
    webServer.on("/style.css", []() { webpage.style(); });

    webServer.onNotFound([]() { webpage.index(); });

    webServer.begin();

    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);
}

void loop()
{
    if ((millis() - lastTick) > 1000) {
        lastTick = millis();
    }
    dnsServer.processNextRequest();
    webServer.handleClient();
}
