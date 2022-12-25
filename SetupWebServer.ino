void SetupWebServer()
{
  Serial.println("[WebServer] Setup");
  webServer.on("/", handleHTML);
  webServer.on("/index.html", handleHTML);
  webServer.on("/style.css", handleCSS);
  webServer.on("/script.js", handleJS);
//  webServer.on("/readACCX", handleACCX);
//  webServer.on("/readACCY", handleACCY);
//  webServer.on("/readACCZ", handleACCZ);
//  webServer.on("/readGYRX", handleGYRX);
//  webServer.on("/readGYRY", handleGYRY);
//  webServer.on("/readGYRZ", handleGYRZ);
//  webServer.on("/readTEMP", handleTEMP);
//  webServer.on("/readALCO", handleALCO);

 
  
  Serial.println("[WebServer] Starting..");
  webServer.begin();
  Serial.println("[WebServer] Running!");
  
}


void handleRoot() {
// String s = MAIN_page; //--> Read HTML contents
 webServer.send(200, "text/html", ""); //--> Send web page
}
void handleFile(char *filename) {
  
  File f = SPIFFS.open(filename, "r");
  if (f){
  String s;
  while (f.available()){
            s += char(f.read());
          }
  webServer.send(200, "text/html", s);
  }
  else {
      webServer.send(200, "text/html", "Error: File does not exist");
  }
}

void handleHTML() {
  handleFile("/index.html");
}

void handleCSS() {
  handleFile("/style.css");
}

void handleJS() {
  handleFile("/script.js");
}
