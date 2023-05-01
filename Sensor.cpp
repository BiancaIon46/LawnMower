#include "sensor.h"

Sensor::Sensor()
{
  this->echoPin = A1;
  this->trigPin = A0;
  this->duration = 0;
  this->distance = 0;
}

void Sensor::setDuration(int duration)
{
  this->duration = duration;
}
void Sensor::setDistance(float distance)
{
  this->distance = distance;
}

int Sensor::getDuration()
{
  return this->duration;
}

float Sensor::getDistance()
{
  return this->distance;
}

int Sensor::getEchoPin()
{
  return this->echoPin;
}

int Sensor::getTrigPin()
{
  return this->trigPin;
}