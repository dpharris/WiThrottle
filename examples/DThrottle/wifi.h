// wifi.h

const std::string ssid = WIFI_SSID;
const std::string password = WIFI_PASSWORD;
const std::string host = JMRI_SERVER_ADDRESS;
const int port = 12090;

void wifiOnConnect() {
  Serial.println("STA Connected");
  Serial.print("STA IPv4: ");
  Serial.println(WiFi.localIP());
  Serial.print("connecting to ");
  Serial.println(host.c_str());
  if (!client.connect(host.c_str(), port)) {
    Serial.println("connection failed");
    return;
  }
  else {
    Serial.println("connected succeeded");
    wiThrottle.connect(&client);
    wiThrottle.setDeviceName("mylittlethrottle");
  }
}

void wifiOnDisconnect() {
  wiThrottle.disconnect();
  Serial.println("STA Disconnected");
  delay(1000);
  WiFi.begin(ssid.c_str(), password.c_str());
}

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case SYSTEM_EVENT_STA_START:
      //set sta hostname here
      WiFi.setHostname("mydigitalclock");
      break;
    case SYSTEM_EVENT_STA_CONNECTED:
      break;
    case SYSTEM_EVENT_AP_STA_GOT_IP6:
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      wifiOnConnect();
      wifi_connected = true;
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      wifi_connected = false;
      wifiOnDisconnect();
      break;
    default:
      break;
  }
}
