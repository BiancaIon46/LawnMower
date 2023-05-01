#pragma once
#include <Arduino.h>

class Airscrew{
private:
    int In1;
    int In2;
    int ENB;
    int SPEED;
    int dir;

public:
  Airscrew();
  void setIn1(int );
  void setIn2(int );
  void setENB(int );
  void setSPEED(int );

  int getIn1();
  int getIn2();
  int getENB();
  int getSPEED();

  void startRotation();
  void stopRotation();
};

