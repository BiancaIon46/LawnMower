#pragma once
#include <Arduino.h>

class Sensor
{
  int echoPin;
  int trigPin;
  
  int duration;
  float distance;

public:
  Sensor();

  void setDuration(int );
  void setDistance(float );

  int getDuration();
  float getDistance();

  int getEchoPin();
  int getTrigPin();
};