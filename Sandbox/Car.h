#pragma once
#include "Automobile.h"
class Car : public Automobile {
 
public:
  //void accelerate() { setSpeed(getSpeed() + 5); } // override
  Car() : Automobile{4} { 
	  
	  // numWheels = 4; // inaccessible bc private
    make = "Tesla";
  };

  void accelerate() {  }
  // could make public setNumWheels in Automobile
  // call Automobile constructor


};
