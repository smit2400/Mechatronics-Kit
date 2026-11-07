//Nano to ESP
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX


void setup() {
  // put your setup code here, to run once:
//  pinMode(5, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
 // digitalWrite(5, HIGH);
  if (analogRead(A0) > 1000)
  {
    mySerial.println('a');
    Serial.println('a');
  }

  if (analogRead(A0) < 300)
  {
    mySerial.println('b');
    Serial.println('b');
  }

  if (analogRead(A1) > 800)
  {
    mySerial.println('c');
    Serial.println('c');
  }

  if (analogRead(A1) < 300)
  {
    mySerial.println('d');
    Serial.println('d');
  }
}
