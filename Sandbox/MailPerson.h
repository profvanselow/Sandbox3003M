#pragma once
#include "Person.h"
class MailPerson : public Person {
 private:
  int num_parcels = 0;
 public:
  std::string drive() override { return "slow"; }
  std::string deliver() { return "here's your package"; }
};
