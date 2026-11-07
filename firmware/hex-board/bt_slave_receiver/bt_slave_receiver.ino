#include <SoftwareSerial.h>
#define tx 2
#define rx 3
SoftwareSerial bt(rx, tx); //RX, TX
void setup()
{
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  pinMode(4, OUTPUT);
}
void loop()
{
  digitalWrite(4,HIGH);
  if(bt.available()>0)
  {
    Serial.println(bt.read());
  }
}
 
