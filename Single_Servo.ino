#include <cvzone.h>
#include <Servo.h>

Servo s1;

SerialData serialData(1,3);
int valsRec[1];

void setup() {
  serialData.begin();
  s1.attach(8);
}

void loop() {

  serialData.Get(valsRec);
  
  s1.write(valsRec[0]);

  Serial.println(valsRec[0]);  
  Serial.println(valsRec[1]);
}
