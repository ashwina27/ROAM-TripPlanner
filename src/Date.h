#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;
    
    bool isValidDate(int d, int m, int y) const;
    int daysInMonth(int m, int y) const;

public:
    Date();
    Date(int d, int m, int y);
    Date(const Date& other);
    ~Date();
    
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);
    
    void display() const;
    string toString() const;
    
    Date& operator=(const Date& other);
    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    
    friend ostream& operator<<(ostream& os, const Date& d);
};

#endif

