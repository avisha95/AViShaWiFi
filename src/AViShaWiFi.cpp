#include "AViShaWiFi.h"

AViShaWiFi::AViShaWiFi() {}

void AViShaWiFi::begin(const char *ssid, const char *password) {
  _ssid = ssid;
  _password = password;
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(_ssid, _password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("[WIFI] Connecting to WiFi ..");
    delay(1000);
  }
  Serial.println("\n[WIFI] Connected to WiFi!");
  Serial.print("[WIFI] IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println();
  Serial.println(F("============================================="));
  Serial.println(F("   █████╗ ██╗   ██╗██╗███████╗██╗  ██╗ █████╗ "));
  Serial.println(F("  ██╔══██╗██║   ██║██║██╔════╝██║  ██║██╔══██╗"));
  Serial.println(F("  ███████║██║   ██║██║███████╗███████║███████║"));
  Serial.println(F("  ██╔══██║╚██╗ ██╔╝██║╚════██║██╔══██║██╔══██║"));
  Serial.println(F("  ██║  ██║ ╚████╔╝ ██║███████║██║  ██║██║  ██║"));
  Serial.println(F("  ╚═╝  ╚═╝  ╚═══╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝"));
  Serial.println(F("============================================="));
  Serial.println(F("AVISHA stands with Palestine"));
  Serial.println(F("Freedom, Justice, and Humanity"));
  Serial.println(F("============================================="));
  Serial.println();
}

String AViShaWiFi::httpsGET(const char *url) {
  String response = "";
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[WIFI] Not connected!");
    return response;
  }

#ifdef ESP8266
  std::unique_ptr<BearSSL::WiFiClientSecure> client(
      new BearSSL::WiFiClientSecure);
  client->setInsecure();
#elif defined(ESP32)
  WiFiClientSecure client;
  client.setInsecure();
#endif

  HTTPClient https;
  if (https.begin(client, url)) {
    int httpCode = https.GET();
    Serial.printf("[HTTP] GET Response code: %d\n", httpCode);
    if (httpCode > 0) {
      response = https.getString();
    }
    https.end();
  }
  return response;
}

String AViShaWiFi::httpsPOST(const char *url, String payload,
                             std::vector<String> headers) {
  String response = "";
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[WIFI] Not connected!");
    return response;
  }

#ifdef ESP8266
  std::unique_ptr<BearSSL::WiFiClientSecure> client(
      new BearSSL::WiFiClientSecure);
  client->setInsecure();
#elif defined(ESP32)
  WiFiClientSecure client;
  client.setInsecure();
#endif

  HTTPClient https;
  if (https.begin(client, url)) {
    for (const String &header : headers) {
      int separatorIndex = header.indexOf(':');
      if (separatorIndex != -1) {
        https.addHeader(header.substring(0, separatorIndex).c_str(),
                        header.substring(separatorIndex + 1).c_str());
      }
    }
    int httpCode = https.POST(payload);
    Serial.printf("[HTTP] POST Response code: %d\n", httpCode);
    if (httpCode > 0) {
      response = https.getString();
    }
    https.end();
  }
  return response;
}

String AViShaWiFi::httpGET(const char *url) {
  String response = "";
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[WIFI] Not connected!");
    return response;
  }

  HTTPClient http;
  if (http.begin(url)) {
    int httpCode = http.GET();
    Serial.printf("[HTTP] GET Response code: %d\n", httpCode);
    if (httpCode > 0) {
      response = http.getString();
    }
    http.end();
  }
  return response;
}

String AViShaWiFi::httpPOST(const char *url, String payload,
                            std::vector<String> headers) {
  String response = "";
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[WIFI] Not connected!");
    return response;
  }

  HTTPClient http;
  if (http.begin(url)) {
    for (const String &header : headers) {
      int separatorIndex = header.indexOf(':');
      if (separatorIndex != -1) {
        http.addHeader(header.substring(0, separatorIndex).c_str(),
                       header.substring(separatorIndex + 1).c_str());
      }
    }
    int httpCode = http.POST(payload);
    Serial.printf("[HTTP] POST Response code: %d\n", httpCode);
    if (httpCode > 0) {
      response = http.getString();
    }
    http.end();
  }
  return response;
}

String AViShaWiFi::httpPOST(const char *url, uint8_t *payload, size_t length,
                            std::vector<String> headers) {
  String response = "";
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[WIFI] Not connected!");
    return response;
  }

  HTTPClient http;
  if (http.begin(url)) {
    for (const String &header : headers) {
      int separatorIndex = header.indexOf(':');
      if (separatorIndex != -1) {
        http.addHeader(header.substring(0, separatorIndex).c_str(),
                       header.substring(separatorIndex + 1).c_str());
      }
    }
    int httpCode = http.POST(payload, length);
    Serial.printf("[HTTP] POST Response code: %d\n", httpCode);
    if (httpCode > 0) {
      response = http.getString();
    }
    http.end();
  }
  return response;
}