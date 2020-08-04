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

const std::string ssid = WIFI_SSID;
const std::string password = WIFI_PASSWORD;
const std::string host = JMRI_SERVER_ADDRESS;
const int port = 12090;
static volatile bool wifi_connected = false;

WiFiClient client;
WiThrottle wiThrottle;

