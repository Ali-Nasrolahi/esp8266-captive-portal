# Captive portal for esp8266

- [Captive portal for esp8266](#captive-portal-for-esp8266)
  - [Description](#description)
  - [Usage](#usage)
  - [Code design](#code-design)
    - [Storage](#storage)
  - [License](#license)
    - [THANKS ;)](#thanks-)

## Description

A **[captive portal]** is a web page accessed with a web browser that is displayed to newly connected users of a Wi-Fi or wired network before they are granted broader access to network resources.  
This implementation uses **DNS redirecting** method for **ESP8266** microchip for Wi-Fi network.

> *Keep in mind:* One of limitation of this method is not being compatible with HTTPS domains, in other words only HTTP domains will be redirected to portal.

## Usage

1. First, clone the project.

    ```bash
    git clone https://github.com/Ali-Nasrolahi/esp8266_captive_portal.git
    ```

2. Then setup your arduino environment and your board programmer. We're using **Wemos d1 r1** board. checkout your vendor page for complete setup.
    > General configurations are available through set of macros included in `include/config.h`.

3. After confirming the configs you could easily upload the sketch and view the result by connecting to created AP.

That's it :smiley:


## Code design

Source code is designed to be easy to expand and modify. If you like to add new webpage or image just add your new method to `Webpage` class implement the handler then pass the **data** or **file path** to `loadFile`.

Just register your handler at `setup` and done!!!

### Storage

An alternative method to display your webpages is to use a filesystem and store pages' data into flash.

To do so:

1. First you need to upload your HTML, CSS, JS, jpeg, ... data to your flash. here we using `LittleFS` to store and retrieve data.
     - > `LittleFS` installation and uploader is available  at [LittleFS-plugin] github page.

2. Enable macro `USE_FS` to use filesystem instead of hard-coded data.

3. Implement your handler and that's all.

## License

GPLv3

### THANKS ;)

[captive portal]: https://en.wikipedia.org/wiki/Captive_portal
[LittleFS-plugin]: https://github.com/earlephilhower/arduino-esp8266littlefs-plugin
