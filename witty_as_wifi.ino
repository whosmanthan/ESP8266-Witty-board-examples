#include <ESP8266WiFi.h>

#define led 2
#define red 15
#define green 12
#define blue 13
#define ldr A0

WiFiClient client;
WiFiServer server(80);  //http port no. 80

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  Serial.begin(9600);

//wittyboard as WiFi/ server

  WiFi.begin("realme 6","0987654321");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print('-');
    delay(200);
  }
  Serial.println();
  Serial.println("witty board connected!");
  Serial.println(WiFi.localIP());
  
//wittyboard as hotspot/ access point

//  WiFi.softAP("manthan","");
//  Serial.println();
//  Serial.println("Witty Board Started !");
//  Serial.println(WiFi.softAPIP());
//  server.begin();
}

void loop() { 
//wittyboard as server
  client = server.available();
  if(client == 1){
    String request = client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if(request == "GET /ledON HTTP/1.1"){
      digitalWrite(red, HIGH);
    }
    else if(request == "GET /ledOFF HTTP/1.1"){
      digitalWrite(red, LOW);
    }
  }
}
