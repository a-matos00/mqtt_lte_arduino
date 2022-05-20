#include <SoftwareSerial.h>
#include <Arduino.h>
SoftwareSerial mySerial(7, 8); //Define virtual serial port name as myseria,Rx is port 7, Tx is port 8
void connectDevice();
void publishData();

void setup()
{
  mySerial.begin(115200); //Initialize virtual serial port
  Serial.begin(115200); //Initialize Arduino default serial port

  connectDevice();
}

void loop()
{
  publishData();
}

void connectDevice(){
  Serial.println("Connecting To Server........");
  mySerial.println("ATE0");
  delay(200);
  mySerial.println("AT+CMQTTSTART"); //Establishing MQTT Connection
  delay(200); 
  mySerial.println("AT+CMQTTACCQ=0,\"andrija\",1"); //Client ID - change this for each client as this need to be unique
  delay(200);
  mySerial.println("AT+CMQTTCONNECT=0,\"tcp://test.mosquitto.org:8883\",90,1"); //MQTT Server Name for connecting this client
  delay(200);
}

void publishData(){
  mySerial.println("AT+CMQTTTOPIC=0,3"); //MQTT Server N
  delay(100);
  mySerial.println("frt"); //MQTT Server N
  delay(100);
  mySerial.println("AT+CMQTTPAYLOAD=0,3"); //MQTT Server N
  delay(100);
  mySerial.println("22"); //MQTT Server N
  delay(100);
  mySerial.println("AT+CMQTTPUB=0,1,60"); //MQTT Server N
  delay(100);
}