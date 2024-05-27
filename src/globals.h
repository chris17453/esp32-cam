// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include "esp_camera.h"
#include <WiFi.h>

// Definition of the Config_t struct
typedef struct {
    char ssid[32];
    char password[32];
    char device_name[32];
    IPAddress local_IP;
    IPAddress gateway;
    IPAddress subnet;
    String secureKey;
    framesize_t frame_size;
    char heartbeat_server[256];
    int heartbeat_interval;
    String fqdn;
    bool debug;
} Config_t;

// Declaration of global variables
extern Config_t system_config;
extern camera_config_t config;

#endif // GLOBALS_H
