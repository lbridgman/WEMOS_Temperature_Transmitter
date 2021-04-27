# WEMOS Temperature Transmitter
_Schematics and code to build a wireless temperature transmitter using an Arduino-based microcontroller._

There are tons of similar projects out there on GitHub, but I found that none directly addressed my particular needs based on my specific microcontroller chipset and the manner in which I wanted to receive the temperature output.

## 1. Use Case
**As an aspiring gardener, I would like to be able to monitor a room's temperature on my phone without having to displace myself.**
I built this project to monitor the relative temperature around the wildflower seedlings I grow in my cold room during the early spring months.  The cold room isn't heated, but should be warm enough relative to our harsh Canadian springs which can often float around 0°C.  

## 2. Finished Product

### Hardware Setup
![wemos](https://user-images.githubusercontent.com/23409144/116263105-18788400-a747-11eb-9ea2-8e82f4452aa0.jpg)

### User Interface
![blynk](https://user-images.githubusercontent.com/23409144/116263337-4a89e600-a747-11eb-9a03-dfcf9e0b9e5b.jpg)

## 3. Shopping List
Category|Description|Available
--------|-----------|---------
Hardware|Wemos D1 mini Pro ESP8266EX (V1.1)|[Manufacturer](https://www.wemos.cc/en/latest/d1/d1_mini_pro.html) or [AliExpress](https://www.aliexpress.com/item/32864534447.html)
Hardware|Solderless Electronics Breadboard|[Example kit I used](https://www.amazon.ca/gp/product/B00DGNZ9G8)
Hardware|1x 10k resistor|[Example kit I used](https://www.amazon.ca/gp/product/B00DGNZ9G8)
Hardware|103 NTC 10k thermistor|[Example kit I used](https://www.amazon.ca/gp/product/B00DGNZ9G8)
Hardware|2x black jumper wires|[Example kit I used](https://www.amazon.ca/gp/product/B00DGNZ9G8)
Hardware|2x red jumper wires|[Example kit I used](https://www.amazon.ca/gp/product/B00DGNZ9G8)
Hardware|1x yellow jumper wire|[Example kit I used](https://www.amazon.ca/gp/product/B00DGNZ9G8)
Hardware|iPhone or Android phone|
Hardware|5V portable USB battery charger|[Example charger I used](https://www.amazon.ca/gp/product/B0194WDVHI)
Software|Arduino IDE|[Download](https://www.arduino.cc/en/software)
Software|Blynk App for iOS or Android|[Download](https://blynk.io/en/getting-started)

## 4. Getting Started

### 4.1 Download and Set Up the Arduino IDE
1. Visit the [Wemos manufacturer website](https://www.wemos.cc/en/latest/ch340_driver.html) to download and install the CH340 driver for the Wemos D1 mini Pro ESP8266EX.
2. Visit the [Arduino Downloads](https://www.arduino.cc/en/software) page to download and install the appropriate installer for your operating system  (Windows, Linux, or MacOS).
3. Run the Arduino IDE.
4. Choose _File -> Preferences_ and entering the following URL in the _Additional Boards Manager_ field: `https://arduino.esp8266.com/stable/package_esp8266com_index.json`.
5. Choose _OK_.
6. Choose _Tools -> Board... -> Boards Manager_, search for `esp8266`, and install the most recent version of the `esp8266` board.
7. Choose _Tools -> Board... -> ESP8266 Boards -> LOLIN(WEMOS) D1 mini Pro_.
8. Choose _Tools -> Manage Libraries ->_, search for `blynk`, and install the most recent version of the `Blynk` library by Volodymyr Shymanskyy.

### 4.2 Download and Set Up the Blynk App
1. Visit the iOS or Google app store to download and install the [Blynk](https://blynk.io/en/getting-started) app.
2. Create a new account in the app using a valid email address. This may require inbox verification.
3. Create a new project using the following settings, then choose _Create Project_ :
  * _Project Name_: TemperatureSensor
  * _Choose Device_: WeMos D1 mini
  * _Connection Type_: WiFi
4. **Note:** A unique authorization token was sent via the email address used in Step 2.  Make reference of this token for the code implementation.

### 4.3 Assemble the Hardware
