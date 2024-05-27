#include "globals.h"
#include "debug.h"
#include "config.h"
#include "wifi.h"
#include "camera.h"
#include "webserver.h"


void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();
  setCpuFrequencyMhz(240);

  if (!loadConfig()) {
    Serial.println("Failed to load config");
    return;
  }
  
  camera_config();
  wifi_connect();

  if(system_config.debug){
    printLoadedConfig();
    printCameraConfig();
    Serial.print("Camera Ready! Use 'http://");
    Serial.print(WiFi.localIP());
    Serial.println("' to connect");
  }

  webserver_start();
}

void loop() {
  delay(10000);
}
