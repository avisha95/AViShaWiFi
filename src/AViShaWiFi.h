#ifndef AVISHAWIFI_H
#define AVISHAWIFI_H

#include <Arduino.h>
#include <vector>

#ifdef ESP8266
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClientSecureBearSSL.h>
#elif defined(ESP32)
  #include <WiFi.h>
  #include <HTTPClient.h>
  #include <WiFiClientSecure.h>
#endif

class AViShaWiFi {
  public:
    AViShaWiFi();
    void begin(const char* ssid, const char* password);
    String httpsGET(const char* url);
    String httpsPOST(const char* url, String payload, std::vector<String> customHeaders);
    String httpGET(const char* url);
    String httpPOST(const char* url, String payload, std::vector<String> customHeaders);
    String httpPOST(const char* url, uint8_t* payload, size_t length, std::vector<String> customHeaders);

  private:
    const char* _ssid;
    const char* _password;
};

#endif