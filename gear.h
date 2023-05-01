#pragma once
#include <Arduino.h>

class Gear{
private:
  int In1;
  int In2;
  int ENA;
  int SPEED1;
  int In3;
  int In4;
  int ENB;
  int SPEED2;
  int dir1;
  int dir2;
  int dir3;
  int dir4;

public:
  Gear();
  void setIn1(int );
  void setIn2(int );
  void setENA(int );
  void setSPEED1(int );

  void setIn3(int );
  void setIn4(int );
  void setENB(int );
  void setSPEED2(int );

  int getIn1();
  int getIn2();
  int getENA();
  int getSPEED1();

  int getIn3();
  int getIn4();
  int getENB();
  int getSPEED2();

  void setForward1();
  void setBackward1();

  void setForward2();
  void setBackward2();

  void turnRight();
  void turnLeft();

  void goForward(int ); // nu cred ca le folosim
  void goBackward(int );

  void runGear();
  void stopGear();
};