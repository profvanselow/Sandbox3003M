#pragma once
#include <string>

class Automobile {
 private:
  int numWheels;
  int speed;  // could have done = 0

 protected:
  std::string make;

 public:
  void accelerate() { ++speed; }
  void brake() { --speed; }
  int getSpeed() { return speed; }
  void setSpeed(int s) { speed = s; }
  Automobile() { speed = 0; }
  Automobile(int n) : speed{0}, numWheels{n} {}  // initialization list (cool)
};
