//Including Libraries
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

// Defining Pin For NodeMcu
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3
#define D10 1

// Wifi Connection Essentials
#define WIFI_SSID     ""   //Wifi name
#define WIFI_PASSWORD ""         //Wifi Password

//you have to enter your own firebase info
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

FirebaseData firebaseData;

// Pin Setup
int relayOnePin   = D0;
int relayTwoPin   = D1;
int relayThreePin = D2;
int relayFourPin  = D3;

  
// Wifi Connection setup
void setup() {
  Serial.begin(9600);
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  delay(1000); 
  
  Serial.print((String)"Connecting to "+WIFI_SSID);
  //Serial.println(ssid);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi connected");  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  Serial.println(" ");
  
  // pin mode
  pinMode(relayOnePin,    OUTPUT);
  pinMode(relayTwoPin,    OUTPUT);
  pinMode(relayThreePin,  OUTPUT);
  pinMode(relayFourPin,   OUTPUT);

  // Firebase with pin setup
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // put your main code here, to run repeatedly:
  String relayOne, relayTwo, relayThree, relayFour;

    if (Firebase.get(firebaseData,"/relayOne")) {
      if (firebaseData.dataType() == "string") {
        relayOne = firebaseData.stringData();
        Serial.print("Relay One: "+relayOne);
            if(relayOne == "1"){
              digitalWrite(relayOnePin, LOW);
            } else {
              digitalWrite(relayOnePin, HIGH);
            }
        }
    }

    if (Firebase.get(firebaseData,"/relayTwo")) {
      if (firebaseData.dataType() == "string") {
        relayTwo = firebaseData.stringData();
        Serial.print(", Relay Two: "+relayTwo);
          if(relayTwo == "1"){
            digitalWrite(relayTwoPin, LOW);
          } else {
            digitalWrite(relayTwoPin, HIGH);
          }
      }
  }

    if (Firebase.get(firebaseData,"/relayThree")) {
      if (firebaseData.dataType() == "string") {
        relayThree = firebaseData.stringData();
        Serial.print(", Relay Three: "+relayThree);
          if(relayThree == "1"){
            digitalWrite(relayThreePin, LOW);
          } else {
            digitalWrite(relayThreePin, HIGH);
          }
      }
  }

    if (Firebase.get(firebaseData,"/relayFour")) {
      if (firebaseData.dataType() == "string") {
        relayFour = firebaseData.stringData();
         Serial.print(", Relay Four: "+relayFour);
          if(relayFour == "1"){
            digitalWrite(relayFourPin, LOW);
          } else {
            digitalWrite(relayFourPin, HIGH);
          }
      }
  }
Serial.println(" ");
}
