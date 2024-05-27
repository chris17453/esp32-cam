#include "config.h"
#include "globals.h"


bool loadConfig() {
  if (!SD_MMC.begin()) {
    Serial.println("Card Mount Failed");
    return false;
  }

  File file = SD_MMC.open("/config.txt");
  if (!file) {
    Serial.println("Failed to open config file");
    return false;
  }

  while (file.available()) {
    String line = file.readStringUntil('\n');
    line.trim();
    int separatorIndex = line.indexOf('=');
    if (separatorIndex < 0) continue;

    String key = line.substring(0, separatorIndex);
    String value = line.substring(separatorIndex + 1);

    if (key == "ssid") {
      value.toCharArray(system_config.ssid, sizeof(system_config.ssid));
    } else if (key == "password") {
      value.toCharArray(system_config.password, sizeof(system_config.password));
    } else if (key == "device_name") {
      value.toCharArray(system_config.device_name, sizeof(system_config.device_name));
    } else if (key == "local_IP") {
      system_config.local_IP.fromString(value);
    } else if (key == "gateway") {
      system_config.gateway.fromString(value);
    } else if (key == "subnet") {
      system_config.subnet.fromString(value);
    } else if (key == "secure_key") {
      system_config.secureKey = value;
    } else if (key == "resolution") {
      if      (value == "96X96") system_config.frame_size=FRAMESIZE_96X96;    // 96x96
      else if (value == "QQVGA") system_config.frame_size=FRAMESIZE_QQVGA;       // 160x120
      else if (value == "QCIF") system_config.frame_size=FRAMESIZE_QCIF;        // 176x144
      else if (value == "HQVGA") system_config.frame_size=FRAMESIZE_HQVGA;       // 240x176
      else if (value == "240X240") system_config.frame_size=FRAMESIZE_240X240;     // 240x240
      else if (value == "QVGA") system_config.frame_size=FRAMESIZE_QVGA;        // 320x240
      else if (value == "CIF") system_config.frame_size=FRAMESIZE_CIF;         // 400x296
      else if (value == "HVGA") system_config.frame_size=FRAMESIZE_HVGA;        // 480x320
      else if (value == "VGA") system_config.frame_size=FRAMESIZE_VGA;         // 640x480
      else if (value == "SVGA") system_config.frame_size=FRAMESIZE_SVGA;        // 800x600
      else if (value == "XGA") system_config.frame_size=FRAMESIZE_XGA;         // 1024x768
      else if (value == "HD") system_config.frame_size=FRAMESIZE_HD;          // 1280x720
      else if (value == "SXGA") system_config.frame_size=FRAMESIZE_SXGA;        // 1280x1024
      else if (value == "UXGA") system_config.frame_size=FRAMESIZE_UXGA;        // 1600x1200
      //3MP Sensors
      else if (value == "FHD") system_config.frame_size=FRAMESIZE_FHD;         // 1920x1080
      else if (value == "P_HD") system_config.frame_size=FRAMESIZE_P_HD;        //  720x1280
      else if (value == "P_3MP") system_config.frame_size=FRAMESIZE_P_3MP;       //  864x1536
      else if (value == "QXGA") system_config.frame_size=FRAMESIZE_QXGA;        // 2048x1536
      //5MP Sensors
      else if (value == "QHD") system_config.frame_size=FRAMESIZE_QHD;         // 2560x1440
      else if (value == "WQXGA") system_config.frame_size=FRAMESIZE_WQXGA;       // 2560x1600
      else if (value == "P_FHD") system_config.frame_size=FRAMESIZE_P_FHD;       // 1080x1920
      else if (value == "QSXGA") system_config.frame_size=FRAMESIZE_QSXGA;       // 2560x1920
      else if (value == "INVALID") system_config.frame_size=FRAMESIZE_INVALID;
    } else if (key == "heartbeat_server") {
      value.toCharArray(system_config.heartbeat_server, sizeof(system_config.heartbeat_server));
    } else if (key == "heartbeat_interval") {
      system_config.heartbeat_interval = value.toInt();
    } else if (key == "fqdn") {
      system_config.fqdn = value;
    } else if (key == "debug") {
      system_config.debug = (value == "true");
    }
  }

  file.close();
  return true;
}
