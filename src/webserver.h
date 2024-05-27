// WEBSERVER_H is used in the ESP webserver lib..
#ifndef _WEBSERVER_H_
#define _WEBSERVER_H_

#include <ESPAsyncWebServer.h>


void handleCapture(AsyncWebServerRequest *request);
void handleSetKey(AsyncWebServerRequest *request);
void handleUploadConfig(AsyncWebServerRequest *request);
void webserver_start();


#endif