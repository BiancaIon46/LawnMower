#include <SoftwareSerial.h>
#include "gear.h"
#include "airscrew.h"
#include "Servo.h"
#include "sensor.h"

Gear g;

char inputB = '0'; 

Servo myservo;
int currentPos = 0;    // variable to store the servo position
int pos = 0;
char level = 0;

char power = '0';

Airscrew as;

Sensor MS;

void setup(){
  Serial.begin(9600);

  as.setIn1(12);
  as.setIn2(13);
  as.setENB(11);

  g.setIn1(8);
  g.setIn2(4);
  g.setENA(3);
  g.setSPEED1(70);

  g.setIn3(5);
  g.setIn4(7);
  g.setENB(6);
  g.setSPEED2(70);

  myservo.attach(10);

  pinMode(MS.getTrigPin(), OUTPUT);
  pinMode(MS.getEchoPin(), INPUT);
}

void loop(){
  digitalWrite(MS.getTrigPin(), LOW);
  delayMicroseconds(2);

  digitalWrite(MS.getTrigPin(), HIGH);
  delayMicroseconds(10);
  digitalWrite(MS.getTrigPin(), LOW);

  MS.setDuration(pulseIn(MS.getEchoPin(), HIGH));

  MS.setDistance(MS.getDuration() * 0.034 / 2); // vine de la viteza luminii

  if (Serial.available() > 0) {
    inputB = Serial.read();

    if (!isAlpha(inputB)) {
      if(inputB == '0' || inputB == '6')
        power = inputB;
      else
        level = inputB;
    }
  }

  Serial.println(MS.getDistance());

  if(inputB == 'F' && MS.getDistance() > 20 && MS.getDistance() > 0) {   // F = go forward
        g.setSPEED1(100);
        g.setSPEED2(100);
        g.setForward2();
        g.setForward1();
        g.runGear();
    } else if(inputB == 'B') { // B = go backward
        g.setSPEED1(100);
        g.setSPEED2(100);
        g.setBackward1();
        g.setBackward2();
        g.runGear();
    } else if(inputB == 'R' && MS.getDistance() > 20 && MS.getDistance() > 0) { // R = turn right
        g.turnRight();
        g.setSPEED1(150);
        g.setSPEED2(0);
        g.runGear();
    }
    else if(inputB == 'L' && MS.getDistance() > 20 && MS.getDistance() > 0) { // L = turn left
      g.turnLeft();
      g.setSPEED1(0);
      g.setSPEED2(150);
      g.runGear();
    }
    else if(inputB == 'S') { // S = stop gear from running
      g.setSPEED1(0);
      g.setSPEED2(0);
      g.stopGear();
    }
    else if(MS.getDistance() <= 20 && MS.getDistance() > 0) {
      g.setSPEED1(0);
      g.setSPEED2(0);
      g.stopGear();
    }


    //Servo
    if(level == '1')
      pos = 36;
    else if(level == '2')
      pos = 72;
    else if(level == '3')
      pos = 108;
    else if(level == '4')
      pos = 144;
    else if(level == '5')
      pos = 180;

    if (currentPos != pos) {
      if (pos > currentPos) {
        for (int i = 0; i <= pos; i += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
        currentPos = pos;
      }
      else {
        for (int i = currentPos; i >= pos; i -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
        currentPos = pos;
      }
    }

  if (power == '6') 
    as.startRotation();
  else 
    as.stopRotation();
}
  
