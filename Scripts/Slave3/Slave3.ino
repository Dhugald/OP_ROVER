// slave for the Middle wheel set of the rover
#include <Arduino.h>
#include <Wire.h>
#include <DCMDriverL298.h>

#define SLAVE 12 //Front Wheel set
#define ANSWER 10 // size of the answer
// Pin Definitions
#define DCMOTORDRIVERL298_PIN_INT1	2
#define DCMOTORDRIVERL298_PIN_ENB	6
#define DCMOTORDRIVERL298_PIN_INT2	3
#define DCMOTORDRIVERL298_PIN_ENA	5
#define DCMOTORDRIVERL298_PIN_INT3	4
#define DCMOTORDRIVERL298_PIN_INT4	7

DCMDriverL298 dcMotorDriverL298 = DCMDriverL298(DCMOTORDRIVERL298_PIN_INT1, DCMOTORDRIVERL298_PIN_ENB, DCMOTORDRIVERL298_PIN_INT2, DCMOTORDRIVERL298_PIN_ENA, DCMOTORDRIVERL298_PIN_INT3, DCMOTORDRIVERL298_PIN_INT4);


void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE);
  //receive the message from the master and use it to get the state of the rover
  Wire.onReceive(receiveEvent);
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
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
}

void Left(){
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
}

void Right(){
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
}

void Back(){
  dcMotorDriverL298.setMotorA(100,0);
  dcMotorDriverL298.setMotorB(100,0);


}

void BackLeft(){
  dcMotorDriverL298.setMotorA(100,0);
  dcMotorDriverL298.setMotorB(100,0);
}

void BackRight(){
  dcMotorDriverL298.setMotorA(100,0);
  dcMotorDriverL298.setMotorB(100,0);
}

void ForwardLeft(){
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);
}

void ForwardRight(){
  dcMotorDriverL298.setMotorA(100,1);
  dcMotorDriverL298.setMotorB(100,1);

}

void Stop(){
  dcMotorDriverL298.stopMotors();
}

void loop() {
  delay(50);
}
