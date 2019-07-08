/*
 * Sketch: ESP8266_LED_Control_05_Station_Mode_with_mDNS
 * Control an LED from a web browser
 * Intended to be run on an a ESP8266
 */
 
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>;
 
// change these values to match your network
char ssid[] = "WLAN3";       //  your network SSID (name)
char pass[] = "87102008970";    // your network password
 
WiFiServer server(80);
 
String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'/><meta charset='utf-8'><style>body {font-size:140%;} #main {display: table; margin: auto;  padding: 0 10px 0 10px; } h2,{text-align:center; } .button { padding:10px 10px 10px 10px; width:100%;  background-color: #4CAF50; font-size: 120%;}</style><title>LED Control</title></head><body><div id='main'><h2>Terra24</h2>";
String html_2 = "";
String html_4 = "</div></body></html>";
 
String request = "";

 
void setup() 
{

 
      Serial.begin(9600);
      delay(500);
      Serial.println(F("Serial started at 9600"));
      Serial.println();
 
      // We start by connecting to a WiFi network
      Serial.print(F("Connecting to "));  Serial.println(ssid);
 
 
      WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
      {
          Serial.print(".");    delay(500);
      }
      Serial.println("");
      Serial.println(F("[CONNECTED]"));
      Serial.print("[IP ");              
      Serial.print(WiFi.localIP()); 
      Serial.println("]");
 
      if (!MDNS.begin("esp8266"))   {  Serial.println("Error setting up MDNS responder!");  }
      else                          {  Serial.println("mDNS responder started");  }
 
      // start a server
      server.begin();
      Serial.println("Server started");
 
} // void setup()
 
 
 
void loop() 
{
 
    // Check if a client has connected
    WiFiClient client = server.available();
    if (!client)  {  return;  }
 
    // Read the first line of the request
    request = client.readStringUntil('\r');
 
  
 
 
    
 
    client.flush();
 
    client.print( header );
    client.print( html_1 );    
    client.print( html_2 );
    client.print( html_4);
 
    delay(5);
  // The client will actually be disconnected when the function returns and 'client' object is detroyed
 
} // void loop()void setup() {}
  // put your setup code here, to run once:
