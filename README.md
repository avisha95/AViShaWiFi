
### AViShaWiFi Library

AViShaWiFi is a simple library for connecting ESP8266 devices to WiFi networks and making HTTP/HTTPS requests. This library provides functions for initiating WiFi connection, making GET and POST requests over both HTTP and HTTPS protocols.

---

## Installation

To use AViShaWiFi library in your Arduino projects, follow these steps:

1. Download the AViShaWiFi-main.zip file from this repository.
2. Open the Arduino IDE.
3. Navigate to `Sketch` -> `Include Library` -> `Add .ZIP Library`.
4. Select the downloaded AViShaWiFi-main.zip file.
5. The library will be added to your Arduino IDE.

---

## Usage

### Initializing AViShaWiFi

To begin using the AViShaWiFi library, you first need to initialize it with your WiFi credentials. Use the `begin()` function to connect to your WiFi network.

```cpp
#include "AViShaWiFi.h"

AViShaWiFi wifi;

void setup() {
  wifi.begin("YourWiFiSSID", "YourWiFiPassword");
}
```

### Making HTTP GET Requests

AViShaWiFi supports making both HTTP GET and POST requests. Use the `httpGET()` and `httpPOST()` functions respectively.

HTTP GET REQUEST

```cpp
#include <AViShaWiFi.h>

const char *ssid = "your-ssid";
const char *password = "your-password";
const char *url = "http://test.kelasrobot.com";

AViShaWiFi wifi;

void setup()
{
  Serial.begin(115200);
  wifi.begin(ssid, password);
}

void loop()
{
  String response = wifi.httpGET(url);
  Serial.println(response);
  delay(15000);
}
```

### Making HTTPS Requests

For HTTPS requests, use the `httpsGET()` and `httpsPOST()` functions. Ensure that the server's SSL certificate is valid.

HTTPS GET REQUEST

```cpp
#include<AViShaWiFi.h>

const char *ssid = "your-ssid";
const char *password = "your-password";
const char *url = "https://test.kelasrobot.com";

AViShaWiFi wifi;

void setup()
{
  Serial.begin(115200);
  wifi.begin(ssid, password);
}

void loop()
{
  String response = wifi.httpsGET(url);
  Serial.println(response);
  delay(15000);
}
```
HTTPS POST REQUEST
```cpp
#include<AViShaWiFi.h>
#include<ArduinoJson.h>

const char* ssid = "WiFiName";
const char* pass = "WiFiPassword";
const char* url = "https://nama-domain.com/send/message";
String uid = "your-uid";

AViShaWiFi wifi;
int tinggiMukaAir = 145;

void setup() {
  Serial.begin(115200);
  wifi.begin(ssid, pass);
}

void loop() {
  std::vector<String> headers;
  headers.push_back("Content-Type:application/json");
  headers.push_back("Accept:application/json");
  headers.push_back("x-uid:" + uid);

  // ArduinoJson
  JsonDocument doc;
  String pesan = String() + "Ketinggian Air: " + tinggiMukaAir;
  doc["message"] = pesan;
  String json;
  serializeJson(doc, json);

  String response = wifi.httpsPOST(url, json, headers);
  Serial.println(response);
  delay(10000);
}
```

---

## Dependencies

- Arduino
- ESP8266WiFi
- ESP8266HTTPClient
- WiFiClientSecureBearSSL

---

## Contributing

If you find any issues or have suggestions for improvement, please feel free to open an issue or create a pull request on GitHub.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```
