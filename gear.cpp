#include "gear.h"

Gear::Gear() {
  
}

//gear 1
void Gear::setIn1(int In1) {
  this->In1 = In1;
}

void Gear::setIn2(int In2) {
  this->In2 = In2;
}

void Gear::setENA(int ENA) {
  this->ENA = ENA;
}

void Gear::setSPEED1(int SPEED1) {
  this->SPEED1 = SPEED1;
}

//gear 2
void Gear::setIn3(int In3) {
  this->In3 = In3;
}

void Gear::setIn4(int In4) {
  this->In4 = In4;
}

void Gear::setENB(int ENB) {
  this->ENB = ENB;
}

void Gear::setSPEED2(int SPEED2) {
  this->SPEED2 = SPEED2;
}

//gear 1
int Gear::getIn1() {
  return this->In1;
}

int Gear::getIn2() {
  return this->In2;
}

int Gear::getENA() {
  return this->ENA;
}

int Gear::getSPEED1() {
  return this->SPEED1;
}

//gear 2
int Gear::getIn3() {
  return this->In3;
}

int Gear::getIn4() {
  return this->In4;
}

int Gear::getENB() {
  return this->ENB;
}

int Gear::getSPEED2() {
  return this->SPEED2;
}

void Gear::setForward1() {
  this->dir1 = HIGH;
  this->dir2 = LOW;
}

void Gear::setBackward1() {
  this->dir1 = LOW;
  this->dir2 = HIGH;
}

void Gear::setForward2() {
  this->dir3 = HIGH;
  this->dir4 = LOW;
}

void Gear::setBackward2() {
  this->dir3 = LOW;
  this->dir4 = HIGH;
}

void Gear::turnRight() {
  this->dir1 = HIGH;
  this->dir2 = LOW;

  this->dir3 = LOW;
  this->dir4 = HIGH;
}

void Gear::turnLeft() {
  this->dir1 = LOW;
  this->dir2 = HIGH;

  this->dir3 = HIGH;
  this->dir4 = LOW;
}

// nu cred ca le folosim
void Gear::goForward(int time) {
  for(int i=0; i<time; i++)
  {
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);

    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
  }
}

void Gear::goBackward(int time) {
  for(int i=0; i<time; i++)
  {
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);

    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);
  }
}



void Gear::runGear() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(In1, this->dir1);
  digitalWrite(In2, this->dir2);

  digitalWrite(In3, this->dir3);
  digitalWrite(In4, this->dir4);

  analogWrite(ENA, SPEED1);
  analogWrite(ENB, SPEED2);
}

void Gear::stopGear() {
  this->SPEED1 = 0;
  this->SPEED2 = 0;

  analogWrite(ENA, SPEED1);
  analogWrite(ENB, SPEED2);
}