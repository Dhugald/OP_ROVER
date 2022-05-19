/*
  The master controller for the rover project.
  uses 4 echo sensors to detect obstacles to all sides of the rover.
  finite state machine to control rover using the information from the sensors.
*/


#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <NewPing.h>

#define sensor1trig  3 //Front trigger
#define sensor1echo  2 //Front echo
#define sensor2trig  5 //Left
#define sensor2echo  4 //Left
#define sensor3trig  7 //Right
#define sensor3echo  6 //Right
#define sensor4trig  9 //Back
#define sensor4echo  8 //Back


#define SLAVE1 10 //Front Wheel set
#define SLAVE2 11 //Middle Wheel set
#define SLAVE3 12 //Back Wheel set

#define ANSWER 10 // size of the answer


NewPing sensor1(sensor1trig, sensor1echo);
NewPing sensor2(sensor2trig, sensor2echo);
NewPing sensor3(sensor3trig, sensor3echo);
NewPing sensor4(sensor4trig, sensor4echo);
enum states {
    FORWARD,
    LEFT,
    RIGHT,
    BACK,
    STOP,
    BACKLEFT,
    BACKRIGHT,
    FORWARDLEFT,
    FORWARDRIGHT,
  };
states state; 
void setup()
{
  Serial.begin(9600);
  Wire.begin();

}
void loop() {
  getState();
  delay(50);
}
//function to return the state of the rover
void getState() {
  int sensor1dist = sensor1.ping_cm();
  int sensor2dist = sensor2.ping_cm();
  int sensor3dist = sensor3.ping_cm();
  int sensor4dist = sensor4.ping_cm();
  Serial.println(sensor1dist);
  Serial.println(sensor2dist);
  Serial.println(sensor3dist);
  Serial.println(sensor4dist);
  
  if (sensor1dist < 15) {
    state = BACK;
  }
  else if (sensor2dist < 15) {
    state = RIGHT;
  }
  else if (sensor3dist < 15) {
    state = LEFT;
  }
  else if (sensor4dist < 15) {
    state = FORWARD;
  }
  else if (sensor1dist < 15 && sensor2dist < 15) {
    state = BACKLEFT;
  }
  else if (sensor1dist < 15 && sensor3dist < 15) {
    state = BACKRIGHT;
  }
  else if (sensor4dist < 15 && sensor2dist < 15) {
    state = FORWARDLEFT;
  }
  else if (sensor4dist < 15 && sensor3dist < 15) {
    state = FORWARDRIGHT;
  }
  else {
    state = FORWARD;
  }
  sendState(state);
}
//function to send the state to the slavess
static sendState(states st) {
  switch (st) {
    case FORWARD:
      Wire.beginTransmission(SLAVE1);
      Wire.write(0);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(0);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(0);
      // Wire.endTransmission();
      break;
    case LEFT:
      Wire.beginTransmission(SLAVE1);
      Wire.write(1);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(1);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(1);
      // Wire.endTransmission();
      break;
    case RIGHT:
      Wire.beginTransmission(SLAVE1);
      Wire.write(2);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(2);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(2);
      // Wire.endTransmission();
      break;
    case BACK:
      Wire.beginTransmission(SLAVE1);
      Wire.write(3);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(3);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(3);
      // Wire.endTransmission();
      break;
    case BACKLEFT:
      Wire.beginTransmission(SLAVE1);
      Wire.write(4);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(4);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(4);
      // Wire.endTransmission();
      break;
    case BACKRIGHT:
      Wire.beginTransmission(SLAVE1);
      Wire.write(5);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(5);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(5);
      // Wire.endTransmission();
      break;
    case FORWARDLEFT:
      Wire.beginTransmission(SLAVE1);
      Wire.write(6);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(6);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(6);
      // Wire.endTransmission();
      break;
    case FORWARDRIGHT:
      Wire.beginTransmission(SLAVE1);
      Wire.write(7);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(7);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(7);
      // Wire.endTransmission();
      break;
    case STOP:
      Wire.beginTransmission(SLAVE1);
      Wire.write(8);
      Wire.endTransmission();
      // Wire.beginTransmission(SLAVE2);
      // Wire.write(8);
      // Wire.endTransmission();
      // Wire.beginTransmission(SLAVE3);
      // Wire.write(8);
      // Wire.endTransmission();
      break;
  }
}
