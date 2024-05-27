#include "wifi.h"
#include "globals.h"



void wifi_connect(){
  WiFi.begin(system_config.ssid, system_config.password);
  WiFi.setHostname(system_config.device_name);
  WiFi.config(system_config.local_IP, system_config.gateway, system_config.subnet);
  WiFi.setSleep(false);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}