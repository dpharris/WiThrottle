/*
 * dthrottle.cpp
 * Implements a WiThrottle based on David Zuhn's WiThrottle lib.
 * built on M5Stick5 with Joystick. 
 *
 * DPHarris 2020
 */
 #define WIFI_SSID     "your_network_name"
#define WIFI_PASSWORD "your_password"
#define JMRI_SERVER_ADDRESS "your JMRI server"

#include <string>
#include <Time.h>
#include <TimeLib.h>
#include <WiFi.h>
#include <WiThrottle.h>
#include "ui.h"
#include "dtwifi.h"

static volatile bool wifi_connected = false;
WiThrottle wiThrottle;
WiFiClient client;

Train curTrain = Train(0, 0);

void setup() {
  Serial.begin(115200);
  WiFi.disconnect();
  WiFi.onEvent(WiFiEvent);
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  
}

void loop() {
  if (wiThrottle.check()) {
    if (wiThrottle.clockChanged) { updateFastTimeDisplay(); }
    if (wiThrottle.protocolVersionChanged) {
        Serial.print("PROTOCOL VERSION "); Serial.println(wiThrottle.protocolVersion);
    }
  }

}
