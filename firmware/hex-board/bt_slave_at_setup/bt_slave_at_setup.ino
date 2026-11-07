
 /*
ENTER THE FOLLOWING AT COMMANDS IN THE SERIAL MONITOR
AT
AT+CMODE?
AT+CMODE=0
AT+ROLE=0
AT+BIND== FCA8,9A,58D5 
*Replace the “:” 
in the master HC05 address with “,” *Here 
I’m using the address of the master HC05 I 
noted down from the previous table. 
You should use the address of your master HC05!
AT+BIND?
*/
#include <SoftwareSerial.h>
#define tx 2
#define rx 3
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
