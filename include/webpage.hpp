/**
 * @file webpage.hpp
 * @author Ali Nasrolahi (a.nasrolahi01@gmail.com)
 * @brief Webpage UI handler.
 * @date 2023-04-02
 */
#pragma once

#include "config.h"

#include <ESP8266WebServer.h>
#include <LittleFS.h>
#include <WString.h>

class Webpage
{
public:
    Webpage(ESP8266WebServer *server);

    /**
     * @brief Main html page.
     *
     */
    void index();

    /**
     * @brief Admin specific page control.
     *
     */
    void admin();

    /**
     * @brief CSS style for index.
     *
     */
    void style();

    /**
     * @brief JS for index.
     *
     */
    void script();

    /**
     * @brief Background for index.
     *
     */
    void background();

    /**
     * @brief Handles POST requests.
     *
     */
    void postHandler();

    /**
     * @brief Temporay method to display recived data.
     * @todo Must be integrated with  'admin()' method.
     */
    void showData();

private:
    /**
     * @brief Extract specific value from recived POST request.
     *
     * @param arg Interested tag name.
     * @return Found value.
     */
    String input(String arg);

    /**
     * @brief Loads the 'file' and send it back to client.
     *
     * @param file file path or file's data.
     * @param content_type type of HTTP content.
     */
    void loadFile(const char *file, const char *content_type = HTTP_HTML);

private:
    /**
     * @brief Pointer to already setup web server.
     *
     */
    ESP8266WebServer *server;

    /**
     * @brief Storage for recived data.
     *
     */
    String data;

    /**
     * @brief ID for CSV output.
     */
    unsigned int id;
};
