#pragma once
#include "Car.h"
class Convertible : public Car {
 private:
  bool topDown;

 public:
  void putTopDown() { topDown = true; }
};
