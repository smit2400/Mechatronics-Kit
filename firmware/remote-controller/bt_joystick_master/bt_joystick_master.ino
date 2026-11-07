 #include <SoftwareSerial.h>
#define tx 3
#define rx 2
SoftwareSerial bt(rx,tx); //RX, TX
#define joyX A0
#define joyY A1

int xValue, yValue;

void setup() 
{
  Serial.begin(9600);
  
  bt.begin(9600);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  //pinMode(4, OUTPUT);
}
void loop() 
{
  //digitalWrite(4,HIGH);
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);

  if(xValue >= 700){bt.write(1);}
  if(xValue <= 300){bt.write(2);}
  if(yValue <= 300){bt.write(3);}
  if(yValue >= 700){bt.write(4);}
  //bt.write(123);
}
