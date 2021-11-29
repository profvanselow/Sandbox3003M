#pragma once
#include "Person.h"
class FireFighter : public Person {
 public:
  std::string drive() { return "fast"; }
};
