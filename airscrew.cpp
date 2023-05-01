#include "airscrew.h"

Airscrew::Airscrew() {
  this->dir = HIGH;
}

void Airscrew::setIn1(int In1) {
  this->In1 = In1;
}

void Airscrew::setIn2(int In2) {
  this->In2 = In2;
}

void Airscrew::setENB(int ENB) {
  this->ENB = ENB;
}

void Airscrew::setSPEED(int SPEED) {
  this->SPEED = SPEED;
}

int Airscrew::getIn1() {
  return this->In1;
}

int Airscrew::getIn2() {
  return this->In2;
}

int Airscrew::getENB() {
  return this->ENB;
}

int Airscrew::getSPEED() {
  return this->SPEED;
}

void Airscrew::startRotation() {
  this->SPEED = 244;

  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);

  analogWrite(ENB, this->SPEED);
}

void Airscrew::stopRotation() {
  this->SPEED = 0;
  analogWrite(ENB, this->SPEED);
}
