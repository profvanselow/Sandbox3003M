#include "Date.h"

// Date constructor
Date::Date() : m_month(11), m_year(2021), m_day(22) { }
// initializer list

Date::Date(int year, int month, int day) { 
	SetDate(year, month, day); 
}

// Date member function aka method
void Date::SetDate(int year, int month, int day) {
  m_month = month;
  m_day = day;
  m_year = year;
}

int Date::operator-(Date d2) { 
	return m_day - d2.getDay(); } 



// The international format defined by ISO (ISO 8601) tries to address all these problems by defining a numerical date system as follows: YYYY-MM-DD where

//YYYY is the year[all the digits, i.e.2012] MM is the
//    month[01(January)to 12(December)] DD is the day[01 to 31] 
std::string Date::GetISODate() {
  return std::to_string(m_year) + std::to_string(m_month) + std::to_string(m_day);

}