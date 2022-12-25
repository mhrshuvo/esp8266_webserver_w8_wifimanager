#include <WiFiManager.h>
#include <ESP8266WebServer.h>
// for file system
#include <FS.h>


ESP8266WebServer webServer(80);

void setup()
{
  WiFi.mode(WIFI_STA);
  Serial.begin(9600); // sensor buart rate
  WiFiManager wm;
  wm.resetSettings();
  bool res;
  res = wm.autoConnect("WaterMonitoring");
  if (!res)
  {
    Serial.println("Failed to connect");
  }
  else
  {

    Serial.println("connected...yeey :)");
  }
  
  Serial.println(WiFi.localIP());
  SetupWebServer();

  SPIFFS.begin();
   

    
}
void loop()
{
 
  webServer.handleClient();
}
