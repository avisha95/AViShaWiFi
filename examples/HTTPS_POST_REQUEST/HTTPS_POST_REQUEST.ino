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