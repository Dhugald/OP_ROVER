// slave for the front wheel set of the rover
#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#define SLAVE 10 //Front Wheel set
#define ANSWER 10 // size of the answer
void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE);
  //recieve the message from the master and use it to get the state of the rover
  Wire.onReceive(receiveEvent);
}

// function to get the state of the rover from the master using i2c communication
void receiveEvent() {
  Wire.available();
  int state = Wire.read();
  if (state == 1) {
    Serial.println("FORWARD");
  }
  else if (state == 2) {
    Serial.println("LEFT");
  }
  else if (state == 3) {
    Serial.println("RIGHT");
  }
  else if (state == 4) {
    Serial.println("BACK");
  }
  else if (state == 5) {
    Serial.println("STOP");
  }
  else if (state == 6) {
    Serial.println("BACKLEFT");
  }
  else if (state == 7) {
    Serial.println("BACKRIGHT");
  }
  else if (state == 8) {
    Serial.println("FORWARDLEFT");
  }
  else if (state == 9) {
    Serial.println("FORWARDRIGHT");
  }
  else {
    Serial.println("FORWARD");
  }
}
void loop() {
  delay(50);
}
