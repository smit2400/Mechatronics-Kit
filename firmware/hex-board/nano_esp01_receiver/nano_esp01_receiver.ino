
 
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
 
void setup()
{
 Serial.begin(9600);
 mySerial.begin(9600);
 delay(5000);
 }
 
void loop()
{
 
 while (mySerial.available())
 {
   Serial.println(mySerial.readString());
  }
 
  
    
  

 }
