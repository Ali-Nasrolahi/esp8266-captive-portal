#include "../include/webpage.hpp"

void Webpage::index()
{
    constexpr auto inx =
        R"(<!DOCTYPE html><html lang="en"><head><meta charset="UTF-8"><title>Login Page with Background Image Example</title><link rel="stylesheet" href="./style.css"></head><body><div id="bg"></div><form><div class="form-field"><input type="email" placeholder="Email / Username" required></div><div class="form-field"><input type="password" placeholder="Password" required></div><div class="form-field"><button class="btn" type="submit">Log in</button></div></form></body></html>)";
    loadFile(inx);
}

void Webpage::admin() { index(); }

void Webpage::style()
{

    constexpr auto inx =
        R"(#bg{color:#47ab11;position:fixed;left:0;top:0;width:100%;height:100%;background-size:cover;filter: blur(2px)}body{font-family:"Lato", sans-serif;color:#4a4a4a;display:flex;justify-content:center;align-items:center;min-height:100vh;overflow:hidden;margin:0;padding:0}form{width:350px;position:relative}form .form-field::before{font-size:20px;position:absolute;left:15px;top:17px;color:#888888;content:" ";display:block;background-size:cover;background-repeat:no-repeat}form .form-field:nth-child(1)::before{width:20px;height:20px;top:15px}form .form-field:nth-child(2)::before{width:16px;height:16px}form .form-field{display:-webkit-box;display:-ms-flexbox;display:flex;-webkit-box-pack:justify;-ms-flex-pack:justify;justify-content:space-between;-webkit-box-align:center;-ms-flex-align:center;align-items:center;margin-bottom:1rem;position:relative}form input{font-family:inherit;width:100%;outline:none;background-color:#fff;border-radius:4px;border:none;display:block;padding:0.9rem 0.7rem;box-shadow:0 3px 6px rgba(0, 0, 0, 0.16);font-size:17px;color:#4a4a4a;text-indent:40px}form .btn{outline:none;border:none;cursor:pointer;display:inline-block;margin:0 auto;padding:0.9rem 2.5rem;text-align:center;background-color:#47ab11;color:#fff;border-radius:4px;box-shadow:0 3px 6px rgba(0, 0, 0, 0.16);font-size:17px})";
    loadFile(inx, HTTP_CSS);
}

void Webpage::script()
{

    constexpr auto inx = R"()";
    loadFile(inx, HTTP_APP_JS);
}

void Webpage::loadFile(const char *file, const char *content_type)
{
#if 0
    File f = SPIFFS.open(file, "r");
    String s;
    while (f.available()) {
        s += char(f.read());
    }
    String str = "";
    Dir dir = SPIFFS.openDir("/");
    while (dir.next()) {
        str += dir.fileName();
        str += " / ";
        str += dir.fileSize();
        str += "\r\n";
    }
    Serial.print(str);
    server.send(200, "text/html", s);

#endif
    server->send(HTTP_SUCCESS, content_type, file);
}