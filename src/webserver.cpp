#include "webserver.h"
#include "globals.h"

AsyncWebServer server(80);

void handleCapture(AsyncWebServerRequest *request) {
  if (!request->hasParam("key", true)) {
    request->send(400, "text/plain", "Missing key parameter");
    return;
  }
  String key = request->getParam("key", true)->value();
  if (key != system_config.secureKey) {
    request->send(403, "text/plain", "Forbidden");
    return;
  }

  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) {
    request->send(500, "text/plain", "Camera capture failed");
    return;
  }

  size_t imageSize = fb->len;
  uint8_t *imageBuffer = new uint8_t[imageSize];
  if (imageBuffer == nullptr) {
    request->send(500, "text/plain", "Memory allocation failed");
    esp_camera_fb_return(fb);
    return;
  }

  memcpy(imageBuffer, fb->buf, imageSize);
  esp_camera_fb_return(fb);

  AsyncWebServerResponse *response = request->beginResponse_P(200, "image/jpeg", imageBuffer, imageSize);
  response->addHeader("Content-Disposition", "inline; filename=capture.jpg");
  request->send(response);

  delete[] imageBuffer;
}

void handleSetKey(AsyncWebServerRequest *request) {
  if (!request->hasParam("new_key", true)) {
    request->send(400, "text/plain", "Missing new_key parameter");
    return;
  }
  String new_key = request->getParam("new_key", true)->value();
  system_config.secureKey = new_key;
  request->send(200, "text/plain", "Key updated successfully");
}

void handleUploadConfig(AsyncWebServerRequest *request) {
  if (!request->hasParam("key", true)) {
    request->send(400, "text/plain", "Missing key parameter");
    return;
  }
  String key = request->getParam("key", true)->value();
  if (key != system_config.secureKey) {
    request->send(403, "text/plain", "Forbidden");
    return;
  }
  if (request->hasParam("config", true)) {
    request->send(200, "text/plain", "Config updated successfully");
    // Logic to update config
  } else {
    request->send(400, "text/plain", "Missing config parameter");
  }
}


void webserver_start() {

  server.on("/capture", HTTP_POST, handleCapture);
  server.on("/setkey", HTTP_POST, handleSetKey);
  server.on("/upload_config", HTTP_POST, handleUploadConfig);

  server.begin();
}
