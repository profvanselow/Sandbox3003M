#ifndef DATE_H
#define DATE_H
#include <string>

class Date {
 private:
  int m_year;
  int m_month;
  int m_day;

 public:
  Date();  // prototype of the constructor
  Date(int year, int month, int day); // prototype of the constructor

  int operator-(Date value);

  void SetDate(int year, int month, int day);
  std::string GetISODate();

  int getYear() { return m_year; }
  int getMonth() { return m_month; }
  int getDay() { return m_day; }
};

#endif