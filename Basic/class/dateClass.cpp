#include <iostream>
#include <cassert>
#include <vector>
class Date {
public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);

private:
  int D ;
  int day_{1};
  int month_{1};
  int year_{0};
  int DaysInMonths( int m, int y) {
      std::vector numDays = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31} ;
      std::cout << m << "\n \n \n" ;
      if ( m == 2 ) {
          if ( y%4 ) {
              return numDays[1] ;
          } else if ( y%100 != 0 ) {
              return 29 ;
          } else if ( y%400 != 0 ) {
              return numDays[1] ;
          } else {
              return 29 ;
          }
      } else {
          return numDays[m-1] ;
      }
  }
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonths(month_, year_))
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
}
