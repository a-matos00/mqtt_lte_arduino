#include <SoftwareSerial.h>
#include <Arduino.h>

void connectDevice();
void publishData();

SoftwareSerial virtualSerial(7, 8); //Define virtual serial port name as myseria,Rx is port 7, Tx is port 8

void setup()
{
  virtualSerial.begin(115200); //Initialize virtual serial port
  Serial.begin(115200); //Initialize Arduino default serial port
  digitalWrite(12, HIGH);
  delay(16000);
  connectDevice();
  digitalWrite(12, LOW);
}

void loop()
{
  publishData();
}

void connectDevice(){
  Serial.println("Connecting To Server........");
  virtualSerial.println("ATE0");
  delay(200);
  virtualSerial.println("AT+CMQTTSTART"); //Establishing MQTT Connection
  delay(200); 
  virtualSerial.println("AT+CMQTTACCQ=0,\"andrija\",1"); //Client ID - change this for each client as this need to be unique
  delay(200);
  virtualSerial.println("AT+CMQTTCONNECT=0,\"tcp://test.mosquitto.org:8883\",90,1"); //MQTT Server Name for connecting this client
  delay(200);
}

void publishData(){
  virtualSerial.println("AT+CMQTTTOPIC=0,3"); 
  delay(100);
  virtualSerial.println("frt");
  delay(100);
  virtualSerial.println("AT+CMQTTPAYLOAD=0,3");
  delay(100);
  virtualSerial.println("22");
  delay(100);
  virtualSerial.println("AT+CMQTTPUB=0,1,60");
  delay(100);

  virtualSerial.println("AT+CMQTTTOPIC=0,3"); 
  delay(100);
  virtualSerial.println("frt");
  delay(100);
  virtualSerial.println("AT+CMQTTPAYLOAD=0,3");
  delay(100);
  virtualSerial.println("24");
  delay(100);
  virtualSerial.println("AT+CMQTTPUB=0,1,60");
  delay(100);

}