
#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

SoftwareSerial Bluetooth(3, 4); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)



int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int speedDelay = 20;
int index = 0;
int dataIn;
int m = 0;

void setup() {
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);
  Serial.begin(9600);
  Bluetooth.begin(9600); // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(1);
  delay(20);
  // Robot arm initial position
//  servo1Pos = 100;
//  servo01.write(servo1Pos);
//  servo2Pos = 100;
//  servo02.write(servo2Pos);
//  servo3Pos = 160;
//  servo03.write(servo3PPos);
//  servo4Pos = 125;
//  servo04.write(servo4PPos);
//  servo5Pos = 30;
//  servo05.write(servo5Pos);
//  servo6Pos = 100;
//  servo06.write(servo6Pos);
  servo1Pos = 90;
  servo01.write(servo1Pos);
  servo2Pos = 90;
  servo02.write(servo2Pos);
  servo3Pos = 90;
  servo03.write(servo3Pos);
  servo4Pos = 95;
  servo04.write(servo4Pos);
  servo5Pos = 90;
  servo05.write(servo5Pos);
  servo6Pos = 90;
  servo06.write(servo6Pos);
}

void basic(){
  servo1Pos = 90;
  servo01.write(servo1Pos);
  servo2Pos = 90;
  servo02.write(servo2Pos);
  servo3Pos = 90;
  servo03.write(servo3Pos);
  servo4Pos = 95;
  servo04.write(servo4Pos);
  servo5Pos = 90;
  servo05.write(servo5Pos);
  servo6Pos = 90;
  servo06.write(servo6Pos);
}

void loop() {
  // Check for incoming data
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.read();  // Read the data

    if (dataIn == 0) {
      m = 0;
    }
    if (dataIn == 1) {
      m = 1;
    }
    if (dataIn == 11) {
      m = 11;
    }
    if (dataIn == 2) {
      m = 2;
    }
    if (dataIn == 22) {
      m = 22;
    }
    if (dataIn == 3) {
      m = 3;
    }
    if (dataIn == 33) {
      m = 33;
    }
    if (dataIn == 4) {
      m = 4;
    }
    if (dataIn == 44) {
      m = 44;
    }
    if (dataIn == 5) {
      m = 5;
    }
    if (dataIn == 55) {
      m = 55;
    }
    if (dataIn == 6) {
      m = 6;
    }
    if (dataIn == 66) {
      m = 66;
    }
    if (dataIn == 99) {
      m = 99;
    }    

    if (m == 99){
      Serial.println("기본자세");
      basic();
      
    }
    // Move robot arm
    // Move servo 1 in positive direction
    while (m == 11) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1Pos);
      servo1Pos++;
      Serial.print("s1 증가 :");
      Serial.println(servo1Pos);
      delay(speedDelay);
    }
    // Move servo 1 in negative direction
    while (m == 1) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo01.write(servo1Pos);
      servo1Pos--;
      Serial.print("s1 감소 :");
      Serial.println(servo1Pos);      
      delay(speedDelay);
    }
    // Move servo 2
    while (m == 22) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2Pos);
      servo2Pos++;
      Serial.print("s2 증가 :");
      Serial.println(servo2Pos);      
      delay(speedDelay);
    }
    while (m == 2) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo02.write(servo2Pos);
      servo2Pos--;
      Serial.print("s2 감소 :");
      Serial.println(servo2Pos);      
      delay(speedDelay);
    }
    // Move servo 3
    while (m == 33) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3Pos);
      servo3Pos++;
      Serial.print("s3 증가 :");
      Serial.println(servo3Pos);            
      delay(speedDelay);
    }
    while (m == 3) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo03.write(servo3Pos);
      servo3Pos--;
      Serial.print("s3 감소 :");
      Serial.println(servo3Pos);            
      delay(speedDelay);
    }
    // Move servo 4
    while (m == 44) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4Pos);
      servo4Pos++;
      Serial.print("s4 증가 :");
      Serial.println(servo4Pos);      
      delay(speedDelay);
    }
    while (m == 4) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo04.write(servo4Pos);
      servo4Pos--;
      Serial.print("s4 감소 :");
      Serial.println(servo4Pos);      
      delay(speedDelay);
    }
    // Move servo 5
    while (m == 55) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5Pos);
      servo5Pos++;
            Serial.print("s5 증가 :");
      Serial.println(servo5Pos);      
      delay(speedDelay);
    }
    while (m == 5) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo05.write(servo5Pos);
      servo5Pos--;
      Serial.print("s5 감소 :");
      Serial.println(servo5Pos);      
      delay(speedDelay);
    }
    // Move servo 6
    while (m == 66) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo06.write(servo6Pos);
      servo6Pos++;
      Serial.print("s6 증가 :");
      Serial.println(servo6Pos);      
      delay(speedDelay);
    }
    while (m == 6) {
      if (Bluetooth.available() > 0) {
        m = Bluetooth.read();
      }
      servo06.write(servo6Pos);
      servo6Pos--;
      Serial.print("s6 감소 :");
      Serial.println(servo6Pos);      
      delay(speedDelay);
    }

    // If arm speed slider is changed
    if (dataIn > 101 & dataIn < 250) {
      speedDelay = dataIn / 10; // Change servo speed (delay time)
    }


  }
 
}
