/*
 * ENTER THE FOLLOWING AT COMMANDS IN THE SERIAL MONITOR
 * AT
 * AT+CMODE?
 * AT+CMODE=1
 * AT+ROLE=1
 * AT+ADDR?
 * +ADDR:FCA8:9A:58D5 OK *This is the address of my master HC05. 
 * Your address will be different!
 */

#include <SoftwareSerial.h>
#define tx 3
#define rx 2
SoftwareSerial configBt(rx, tx); // RX, TX
void setup()
{
  Serial.begin(38400);
  configBt.begin(38400);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
}
void loop()
{
  if(configBt.available()) //if the bluetooth module is sending something...
  {
    Serial.print(configBt.readString()); //print whatever the bluetooth module is sending
  }
   
  if(Serial.available()) //if we have typed anything into the serial monitor input text box...
  {
    configBt.write(Serial.read()); //write whatever we typed into the serial monitor input text box to the bluetooth module
  }
}
