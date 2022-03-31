#include<ESP8266WiFi.h>
#include<ThingSpeak.h>

//pinout for wittyBoard 
#define led   2
#define red   15
#define green 12
#define blue  13
#define ldr   A0

//WiFiClient client;     //define client
//WiFiServer server(80); //define server, 80 is the port number for HTTP.

  //wittyBoard as a ThingSpeak
 WiFiClient client;     //define client
  long myChannelNumber = "YOUR CHANNEL NUMBER";
  const char myWriteAPIKey[] = "API KEY";


void setup() {
  // pin definations
  pinMode (led,OUTPUT);
  pinMode (red,OUTPUT);
  pinMode (green,OUTPUT);
  pinMode (blue,OUTPUT);

  Serial.begin(9600);

  //wittyBoard with ThingSpeak
  WiFi.begin("WiFi_Name","WiFi_PASSWORD");
  while(WiFi.status()!= WL_CONNECTED){ //WL_IDLE_STATUS, WL_CONNECT_FAILED
    Serial.print('.');
    delay(200);
  }
  Serial.println();
  Serial.println("Witty Board connected");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  
}

void loop() {
// wittyBoard with ThingSpeak
  int value = analogRead(ldr);
  Serial.println(value);
  ThingSpeak.writeField(myChannelNumber, 1, value, myWriteAPIKey);
   
}
