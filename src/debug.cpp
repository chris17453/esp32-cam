#include "debug.h"
#include "globals.h"

void printCameraConfig() {
  Serial.println("Camera Configuration:");
    if      (config.frame_size==FRAMESIZE_96X96)  Serial.println("Frame Size: 96x96 - 96x96");        // 96x96
    else if (config.frame_size==FRAMESIZE_QQVGA)  Serial.println("Frame Size: QQVGA - 160x120");        // 160x120
    else if (config.frame_size==FRAMESIZE_QCIF)  Serial.println("Frame Size: QCIF - 176x144");         // 176x144
    else if (config.frame_size==FRAMESIZE_HQVGA)  Serial.println("Frame Size: HQVGA - 240x176");        // 240x176
    else if (config.frame_size==FRAMESIZE_240X240)  Serial.println("Frame Size: 240X240 - 240x240");      // 240x240
    else if (config.frame_size==FRAMESIZE_QVGA)  Serial.println("Frame Size: QVGA - 320x240");         // 320x240
    else if (config.frame_size==FRAMESIZE_CIF)  Serial.println("Frame Size: CIF - 400x296");         // 400x296
    else if (config.frame_size==FRAMESIZE_HVGA)  Serial.println("Frame Size: HVGA - 480x320");         // 480x320
    else if (config.frame_size==FRAMESIZE_VGA)  Serial.println("Frame Size: VGA - 640x480");         // 640x480
    else if (config.frame_size==FRAMESIZE_SVGA)  Serial.println("Frame Size: SVGA - 800x600");         // 800x600
    else if (config.frame_size==FRAMESIZE_XGA)  Serial.println("Frame Size: XGA - 1024x768");         // 1024x768
    else if (config.frame_size==FRAMESIZE_HD)  Serial.println("Frame Size: HD  - 1280x720");         // 1280x720
    else if (config.frame_size==FRAMESIZE_SXGA)  Serial.println("Frame Size: SXGA - 1280x1024");         // 1280x1024
    else if (config.frame_size==FRAMESIZE_UXGA)  Serial.println("Frame Size: UXGA - 1600x1200");         // 1600x1200
    //3MP Sensors
    else if (config.frame_size==FRAMESIZE_FHD)  Serial.println("Frame Size: value - 1920x1080");         // 1920x1080
    else if (config.frame_size==FRAMESIZE_P_HD)  Serial.println("Frame Size: P_HD - 720x1280");         //  720x1280
    else if (config.frame_size==FRAMESIZE_P_3MP)  Serial.println("Frame Size: P_3MP - 864x1536");        //  864x1536
    else if (config.frame_size==FRAMESIZE_QXGA)  Serial.println("Frame Size: QXGA - 2048x1536");         // 2048x1536
    //5MP Sensors
    else if (config.frame_size==FRAMESIZE_QHD)  Serial.println("Frame Size: value - 2560x1440");        // 2560x1440
    else if (config.frame_size==FRAMESIZE_WQXGA)  Serial.println("Frame Size: WQXGA - 2560x1600");        // 2560x1600
    else if (config.frame_size==FRAMESIZE_P_FHD)  Serial.println("Frame Size: P_FHD - 1080x1920");        // 1080x1920
    else if (config.frame_size==FRAMESIZE_QSXGA)  Serial.println("Frame Size: QSXGA - 2560x1920");        // 2560x1920
    else if (config.frame_size==FRAMESIZE_INVALID)  Serial.println("Frame Size: INVALID") ;
  
  Serial.printf("  LEDC channel: %d\n", config.ledc_channel);
  Serial.printf("  LEDC timer: %d\n", config.ledc_timer);
  Serial.printf("  Pixel format: %d\n", config.pixel_format);
  Serial.printf("  JPEG quality: %d\n", config.jpeg_quality);
  Serial.printf("  FB count: %d\n", config.fb_count);
  Serial.printf("  FB location: %d\n", config.fb_location);
  Serial.printf("  Grab mode: %d\n", config.grab_mode);
}

void printLoadedConfig() {
   
  Serial.println("Loaded Configuration:");
  if (system_config.debug) Serial.printf("  Debug: true\n");
  else  Serial.printf("  Debug: false\n");

  Serial.printf("  SSID: %s\n", system_config.ssid);
  Serial.printf("  Password: %s\n", system_config.password);
  Serial.printf("  Device Name: %s\n", system_config.device_name);
  Serial.printf("  Local IP: %s\n", system_config.local_IP.toString().c_str());
  Serial.printf("  Gateway: %s\n", system_config.gateway.toString().c_str());
  Serial.printf("  Subnet: %s\n", system_config.subnet.toString().c_str());
  Serial.printf("  Secure Key: %s\n", system_config.secureKey.c_str());
  
  // Print the frame size as a human-readable string
  const char* frameSizeStr;
  switch(system_config.frame_size) {
    case FRAMESIZE_96X96: frameSizeStr = "96x96"; break;
    case FRAMESIZE_QQVGA: frameSizeStr = "QQVGA (160x120)"; break;
    case FRAMESIZE_QCIF: frameSizeStr = "QCIF (176x144)"; break;
    case FRAMESIZE_HQVGA: frameSizeStr = "HQVGA (240x176)"; break;
    case FRAMESIZE_240X240: frameSizeStr = "240x240"; break;
    case FRAMESIZE_QVGA: frameSizeStr = "QVGA (320x240)"; break;
    case FRAMESIZE_CIF: frameSizeStr = "CIF (400x296)"; break;
    case FRAMESIZE_HVGA: frameSizeStr = "HVGA (480x320)"; break;
    case FRAMESIZE_VGA: frameSizeStr = "VGA (640x480)"; break;
    case FRAMESIZE_SVGA: frameSizeStr = "SVGA (800x600)"; break;
    case FRAMESIZE_XGA: frameSizeStr = "XGA (1024x768)"; break;
    case FRAMESIZE_HD: frameSizeStr = "HD (1280x720)"; break;
    case FRAMESIZE_SXGA: frameSizeStr = "SXGA (1280x1024)"; break;
    case FRAMESIZE_UXGA: frameSizeStr = "UXGA (1600x1200)"; break;
    case FRAMESIZE_FHD: frameSizeStr = "FHD (1920x1080)"; break;
    case FRAMESIZE_P_HD: frameSizeStr = "P_HD (720x1280)"; break;
    case FRAMESIZE_P_3MP: frameSizeStr = "P_3MP (864x1536)"; break;
    case FRAMESIZE_QXGA: frameSizeStr = "QXGA (2048x1536)"; break;
    case FRAMESIZE_QHD: frameSizeStr = "QHD (2560x1440)"; break;
    case FRAMESIZE_WQXGA: frameSizeStr = "WQXGA (2560x1600)"; break;
    case FRAMESIZE_P_FHD: frameSizeStr = "P_FHD (1080x1920)"; break;
    case FRAMESIZE_QSXGA: frameSizeStr = "QSXGA (2560x1920)"; break;
    case FRAMESIZE_INVALID: frameSizeStr = "INVALID"; break;
    default: frameSizeStr = "UNKNOWN"; break;
  }
  Serial.printf("  Frame Size: %s\n", frameSizeStr);
  
  Serial.printf("  Heartbeat Server: %s\n", system_config.heartbeat_server);
  Serial.printf("  Heartbeat Interval: %d\n", system_config.heartbeat_interval);
  Serial.printf("  FQDN: %s\n", system_config.fqdn.c_str());
}
