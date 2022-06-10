// slave for the front wheel set of the rover
#include <Arduino.h>
#include <Wire.h>
#include <DCMDriverL298.h>

#define SLAVE 10 //Front Wheel set
#define ANSWER 10 // size of the answer
// Pin Definitions
#define DCMOTORDRIVERL298_PIN_INT1	2
#define DCMOTORDRIVERL298_PIN_ENB	6
#define DCMOTORDRIVERL298_PIN_INT2	3
#define DCMOTORDRIVERL298_PIN_ENA	5
#define DCMOTORDRIVERL298_PIN_INT3	4
#define DCMOTORDRIVERL298_PIN_INT4	7

DCMDriverL298 dcMotorDriverL298 = DCMDriverL298(DCMOTORDRIVERL298_PIN_INT1, DCMOTORDRIVERL298_PIN_ENB, DCMOTORDRIVERL298_PIN_INT2, DCMOTORDRIVERL298_PIN_ENA, DCMOTORDRIVERL298_PIN_INT3, DCMOTORDRIVERL298_PIN_INT4);

//Stepper motor pins
const int stepPin1 = 8; 
const int dirPin1 = 9;
const int stepPin2 = 10;
const int dirPin2 = 11;


void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE);
  //receive the message from the master and use it to get the state of the rover
  Wire.onReceive(receiveEvent);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}

// function to get the state of the rover from the master using i2c communication
void receiveEvent() {
  Wire.available();
  int state = Wire.read();
  Serial.println(state);
  switch(state){
    case 0:
      Serial.println("FORWARD");
      Forward();
      break;
    case 1:
      Serial.println("LEFT");
      Left();
      break;
    case 2: 
      Serial.println("RIGHT");
      Right();
      break;
    case 3: 
      Serial.println("BACK");
      Back();
      break;
    case 4: 
      Serial.println("BACKLEFT");
      BackLeft();
      break;
    case 5: 
      Serial.println("BACKRIGHT");
      BackRight();
      break;
    case 6: 
      Serial.println("FORWARDLEFT");
      ForwardLeft();
      break;
    case 7: 
      Serial.println("FORWARDRIGHT");
      ForwardRight();
      break;
    case 8:
      Serial.println("STOP");
      Stop();
      break;
    default:  
      Serial.println("ERROR");
      Stop();
      break;
  }
}
//Forward powers the DC motors to move the rover forward, Stepper motors are stationary 
void Forward(){
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
  
}

void Left(){
  //rotate the steppers 90 degrees to the left and drive the rover forward
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
  //rotate the steppers back to the original position
  digityalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);


}

void Right(){
  //rotate the steppers 90 degrees to the right and drive the rover forward
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
  //rotate the steppers back to the original position
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);


}

void Back(){
  //drive the DC motors backward and stop the steppers
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  dcMotorDriverL298.setMotorA(100,0);
  dcMotorDriverL298.setMotorB(100,0);


}

void BackLeft(){
  //reverse the DC motors and rotate the steppers 90 degrees to the left
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  dcMotorDriverL298.setMotorA(100,0);
  dcMotorDriverL298.setMotorB(100,0);
  //rotate the steppers back to the original position
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);

}

void BackRight(){
  //reverse the DC motors and rotate the steppers 90 degrees to the right
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);

  dcMotorDriverL298.setMotorA(100,0);
  dcMotorDriverL298.setMotorB(100,0);

  //rotate the steppers back to the original position
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
}

void ForwardLeft(){
  //turn the motors 90 degrees to the left and drive the rover forward
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
  //Rotate the steppers back to their original position
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);


}

void ForwardRight(){
  //turn the motors 90 degrees to the right and drive the rover forward
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
  //Rotate the steppers back to their original position
  digitalWrite(stepPin1, HIGH);
  digitalWrite(stepPin2, HIGH);
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
}

void Stop(){
  dcMotorDriverL298.stopMotors();
  digitalWrite(stepPin1, LOW);
  digitalWrite(stepPin2, LOW);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
}

void loop() {
  delay(50);
}
