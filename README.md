# NanoCell-C3
This is the repository of my NanoCell-C3 project, which includes an ESP32 development board I made to simplify the creation of small battery-powered devices for use with Home Assistant and ESPHome.

## Description
### Hardware
NanoCell-C3 is a development board using an ESP32 microcontroller, intended -but not restricted- to be used with Home Assistant. Its main features are:
* USB type-C port for charging and uploading firmware
* Li-ion/Li-po battery management IC
* Li-ion/Li-po battery charging IC
* Battery capacity measurement IC, accessible via I2C on pins 2 and 3.
* RESET and BOOT pushbuttons
* Charging and USB-power LED indicators
* 2.54mm pin headers breaking out all the pins of ESP32-C3, as well as the USB, battery, and LDO voltage.

### Tests
| Idle Power Consumption: 66.1μA                                                                                                                          | Max Charging Current: 464mA                                                                                         | VCC Output @ 4.2V input: 3.356V                                                                                       | VCC Output @ 3V input: 3.359V                                                                                       |
|-------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|
| <img src="https://github.com/Frapais/NanoCell-C3/blob/main/Tests/Idle%20consumption%20at%204.2V.jpg" alt="Idle Power Consumption" width="300"/> | <img src="https://github.com/Frapais/NanoCell-C3/blob/main/Tests/Max%20charging%20current.jpg" width="300"/> | <img src="https://github.com/Frapais/NanoCell-C3/blob/main/Tests/VCC%20voltage%20at%204.2V.jpg" width="300"/> | <img src="https://github.com/Frapais/NanoCell-C3/blob/main/Tests/VCC%20voltage%20at%203V.jpg" width="300"/> |

The Idle Power Consumption image shows the consumption of all the components of the board except the ESP32 module, as its consumption fluctuates depending on the tasks it's running. Therefore, if you want to calculate the battery life of your project, you should expect at least 66μA of current, in addition to the current consumption of the ESP32 module.

### Initial Home Assistant setup
#### Requirements:
* Access to Home Assistant Dashboard
* Installed ESPHome plugin

#### Setup process:
1. Connect the NanoCell-C3 board on the computer running Home Assistant, while pressing the BOOT button
2. Open ESPHome, and add a new device as shown [here](https://esphome.io/guides/getting_started_hassio#dashboard-interface)
3. Select "Connect" to upload the initialization firmware on the board, and select the correct port from the popup window. (It usually shows up as a "USB JTAG" device).
4. Wait for the upload to finish, and restart the NanoCell-C3. Now, every time you power on the device, it should connect to your WiFi automatically.
5. Last step, is to go to your Home Assistant settings, and Configure your newly discovered device (assuming it is powered on and visible on the network).

## Support
If you find this project useful, please consider supporting me on any of the following platforms:
* PayPal:
  * <a href="https://www.paypal.com/paypalme/kostasparaskevas">
    <img src="https://img.shields.io/badge/$-donate-ff69b4.svg?maxAge=2592000&style=flat">
* Buy Me a Coffe:
  * <a href="https://www.buymeacoffee.com/frapais" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/purple_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px     3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>
* Instagram:
  * [@frapais.lab](https://www.instagram.com/frapais.lab/)



