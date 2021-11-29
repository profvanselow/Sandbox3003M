#pragma once
#include <string>

class Person {
 private:
  int age = 0;
  std::string name;
  std::string dob;

 public:
  virtual std::string drive()  { return "normal"; }
  // the keyword virtual is used when a function is intended
  // to be overriden 

    virtual int get_older() { return ++age; }

};
