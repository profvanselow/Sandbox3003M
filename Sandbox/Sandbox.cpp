/** @file Sandbox.cpp

 *  @brief This file contains the 'main' function. Program execution

 *

 *  @author Prof. Vanselow

 *  @bug No known bugs.

 */

#include <fstream>
#include <iostream>
#include <string>
#include <math.h>

#include "Accumulator.h"
#include "Automobile.h"
#include "Calc.h"
#include "Car.h"
#include "Convertible.h"
#include "Date.h"
#include "FireFighter.h"
#include "MailPerson.h"
#include "Person.h"
#include "Truck.h"

void meal_price_calculator();
void demo_save_to_file();
void demo_read_from_file();
// void calc_total_meal_price(double meal_price); // function prototype, forward
// declaration
// not needed when included in .h file
void procedural_stack_demo(void);
void object_oriented_stack_demo(void);
void demo_date();
void friends();
void reset(Accumulator& accumulator);
void demo_inheritance();
void demo_polymorphism();
void demo_exceptions();
void demo_generics();
// abbreviated function template
auto add_nums(auto num1, auto num2) {
    return num1 + num2;
}
int calculate_difference(Date, Date);

class Stack {
  // fields
 private:
  int stackstore[100];
  int stack_pointer;

  // methods
 public:
  // This is a constructor.
  // It is a special method.
  // no return type
  // name has to be the same as the class
  // MUST be public
  // called automatically when object gets created
  // if no constructor is written the compiler makes
  // default
  // need one when we want code to happen when object
  // gets created
  Stack(void) { stack_pointer = 0; }
  Stack(int num) {  // overloaded constructor
                    // stack_pointer = num; // wouldn't really want to do this
  }

  void push(int value);
  int pop(void) { return stackstore[--stack_pointer]; }
};

void Stack::push(int value) { stackstore[stack_pointer++] = value; }

int main() {
  // std::cout << "Hello World!\a";  // audible
  // https://en.cppreference.com/w/cpp/language/escape
  bool continue_program = true;
  int choice{};
  while (continue_program) {
    std::cout << "Enter your choice: \n";
    std::cout << "1. Meal Price Calculator \n";
    std::cout << "2. procedural_stack_demo \n";
    std::cout << "3. object_oriented_stack_demo \n";
    std::cout << "4. demo_save_to_file \n";
    std::cout << "5. demo_read_from_filer \n";
    std::cout << "6. demo_date \n";
    std::cout << "7. Friends \n";
    std::cout << "8. Inheritance \n";
    std::cout << "9. Polymorphism \n";
    std::cout << "10. Exceptions \n";
    std::cout << "11. Templates \n";
    std::cout << "12. Quit \n";
    std::cin >> choice;
    switch (choice) {
      case 1: {
        meal_price_calculator();
        break;
      }
      case 2: {
        procedural_stack_demo();
        break;
      }
      case 3: {
        object_oriented_stack_demo();
        break;
      }
      case 4: {
        demo_save_to_file();
        break;
      }
      case 5: {
        demo_read_from_file();
        break;
      }
      case 6: {
        demo_date();
        break;
      }
      case 7: {
        friends();
        break;
      }
      case 8: {
        demo_inheritance();
        break;
      }
      case 9: {
        demo_polymorphism();
        break;
      }
      case 10: {
        try {
          demo_exceptions();
        } catch (const std::exception& ex) {
          std::cout << "Caught in main. " << ex.what() << std::endl;
        }
        
        break;
      }
      case 11: {
        demo_generics();
        break;
      }

      case 12: {
        continue_program = false;
        break;
      }
      default: {
        std::cout << "Invalid selection. Try again.\n";
      }
    }
  }
  return 0;  // status code
}

void demo_generics() {
  int int1 = 1;
  int int2 = 2;
  double dbl1 = 1;
  double dbl2 = 2;
  std::cout << add_nums(int1, int2) << std::endl;
  std::cout << add_nums(dbl1, dbl2) << std::endl;
  std::cout << add_nums(int1, dbl2) << std::endl;
}

// add_nums for ints only
//int add_nums(int num1, int int2) { return num1 + int2; }

// add_nums for doubles only using overloading
//double add_nums(double num1, double int2) { return num1 + int2; }

//template <typename T>
//T add_nums(T num1, T num2) {
//  return num1 + num2;
//}



void demo_exceptions() {
  int num2 = 0;
 
  try {
    int num1 = 1;
    if (num2 == 0) {
      throw std::invalid_argument("");
    }
    std::cout << 5 / num2;
  //} catch (const std::invalid_argument& ex) {
   // std::cout << "Can't divide by 0" << std::endl;
  //} catch (const std::exception& ex) {  // polymorphism
    //std::cout << "Caught you" << std::endl;
  } catch (...) {
    std::cout << "Caught all you" << std::endl;
  }
  //std::cout << num1 << std::endl;// out of scope
}

void demo_polymorphism() {
  Person ryan;
  // std::cout << ryan << std::endl;
  std::cout << ryan.drive() << std::endl;
  MailPerson aiden;
  std::cout << aiden.drive() << std::endl;
  FireFighter jairo;
  std::cout << jairo.drive() << std::endl;

  Person* regularPerson = new Person;
  std::cout << regularPerson->drive() << std::endl;
  std::cout << regularPerson->get_older() << std::endl;

  Person* jobUnknown = NULL;
  std::cout << "Enter the job. 1 for Mail, 2 for Fire" << std::endl;
  int job_code;
  std::cin >> job_code;
  if (job_code == 1) {
    jobUnknown = new MailPerson;
  }
  if (job_code == 2) {
    jobUnknown = new FireFighter;
  }

  // std::cout << static_cast<MailPerson *>(jobUnknown)->drive() << std::endl;
  std::cout << jobUnknown->drive() << std::endl;
  std::cout << jobUnknown->get_older() << std::endl;
  std::cout << jobUnknown << std::endl;
}

void demo_inheritance() {
  Automobile myAuto;  // makes an Automobile object
  myAuto.accelerate();
  std::cout << myAuto.getSpeed() << std::endl;
  Car myCar;
  myCar.accelerate();
  // myCar.make = "Tesla"; // inaccessible bc protected
  std::cout << myCar.getSpeed() << std::endl;  // inheritance! huzzah!
  Convertible myConvertible;
  myConvertible.accelerate();
  myConvertible.putTopDown();
  std::cout << myConvertible.getSpeed() << std::endl;
  // myCar.putTopDown(); // illegal
  Truck myTruck;
  myTruck.accelerate();
  std::cout << myTruck.getSpeed() << std::endl;

  Automobile* yourAuto = new Car();
  static_cast<Car*>(yourAuto)->accelerate();
  std::cout << yourAuto->getSpeed() << std::endl;
}

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator) {
  // And can access the private data of Accumulator objects
  accumulator.m_value = 0;
}

void friends() {
  Accumulator acc;
  acc.add(5);  // add 5 to the accumulator
  reset(acc);  // reset the accumulator to 0
}

void demo_date() {
  Date halloween(2021, 10, 31);
  std::cout << halloween.getMonth() << std::endl;
  Date today;
  std::cout << today.getMonth() << std::endl;
  std::cout << calculate_difference(halloween, today) << std::endl;
  std::cout << halloween - today << std::endl;
  //std::cout << halloween;
}

int calculate_difference(Date d1, Date d2) { 
    return d1.getDay() - d2.getDay(); }

int stack[100];  // global variable, bad because harder to
// debug
int SP = 0;

void push(int value) {
  stack[SP++] = value;  // increment operator in postfix
}

int pop(void) {
  return stack[--SP];  // decrement operator in prefix
}

void procedural_stack_demo() {
  push(3);
  push(2);
  push(1);
  std::cout << pop() << std::endl;  // :: scope resolution
  // operator
  // SP = 111; // being able to do something like this is
  // dangerous and bad
  std::cout << pop() << std::endl;
  std::cout << pop() << std::endl;
}

void object_oriented_stack_demo() {
  Stack little_stack;   // creation of a Stack object
  Stack another_stack;  // call to the constructor
  Stack funny_stack;

  little_stack.push(1);
  another_stack.push(little_stack.pop() + 1);
  funny_stack.push(another_stack.pop() + 2);
  std::cout << funny_stack.pop() << std::endl;
}

void demo_save_to_file() {
  std::ofstream myfile("example.txt");
  // class object
  // class is kind of like a data type
  // an object is kind of like a variable
  if (myfile.is_open())  // is_open is a function in
                         // the class aka a method
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    std::cout << "Text save to file\n";
    myfile.close();
  } else
    std::cout << "Unable to open file";
}

void demo_read_from_file() {
  std::string line;
  std::ifstream myfile("example.txt");
  if (myfile.is_open()) {
    while (std::getline(myfile, line)) {
      std::cout << line << '\n';
    }
    myfile.close();
  }

  else
    std::cout << "Unable to open file";
}

void meal_price_calculator() {
  std::cout << "Enter the price of the meal: ";  // ask user for a number

  double meal_price{};     // define variable meal_price to hold user input
  std::cin >> meal_price;  // get number from keyboard and store it in variable

  double total_price =
      calc_total_meal_price(meal_price);  // function call(argument)

  std::cout << "The total price with tax and tip is " << total_price
            << '\n';  // out of scope}
}
