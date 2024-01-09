#include <cvzone.h>
#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;
Servo s6;

SerialData serialData(1,1);

int valsRec[1];

void setup() {
  
  serialData.begin();
  
  s1.attach(5);
  s2.attach(6);
  s3.attach(7);
  s4.attach(8);
  s5.attach(9);        
  s6.attach(10);          
  
  stand_on();
  
}

void loop() {

  serialData.Get(valsRec);
   
//  Serial.println(valsRec[0]);  
  int result = (valsRec[0]);

  if (result == 1){
    up();
  } else if(result == 2){
    down();
  } else if(result == 3){
    left();
  } else if(result == 4){
    right();
  } else if(result == 5){
    stand_on();
  }
  
//  Serial.print("결과 ");
//  Serial.println(result); 
  
}

void up() {
  Serial.println("위");
}

void down() {
  Serial.println("아래");
}

void left() {
  Serial.println("왼쪽");  
}

void right() {
  Serial.println("오른쪽");
}

void stand_on() {
  Serial.println("준비");
}
