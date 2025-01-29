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