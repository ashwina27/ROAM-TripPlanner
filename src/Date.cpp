#include "Date.h"
#include "Trace.h"

bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool Date::isValidDate(int d, int m, int y) const {
    if (m < 1 || m > 12) return false;
    if (y < 1900 || y > 2100) return false;
    if (d < 1 || d > daysInMonth(m, y)) return false;
    return true;
}

int Date::daysInMonth(int m, int y) const {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y))
        return 29;
    return days[m];
}

Date::Date() : day(1), month(1), year(2024) {
    if (Trace::on)
        cout << ">> Date constructor (default): Date created\n";
}

Date::Date(int d, int m, int y) {
    if (isValidDate(d, m, y)) {
        day = d;
        month = m;
        year = y;
    } else {
        day = 1;
        month = 1;
        year = 2024;
    }
    if (Trace::on)
        cout << ">> Date constructor (parameterized): Date " << day << "-" 
             << month << "-" << year << " created\n";
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {
    if (Trace::on)
        cout << ">> Date copy constructor: Date copied\n";
}

Date::~Date() {
    if (Trace::on)
        cout << ">> Date destructor: Date destroyed\n";
}

bool Date::setDay(int d) {
    if (d >= 1 && d <= daysInMonth(month, year)) {
        day = d;
        return true;
    }
    return false;
}

bool Date::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
        if (day > daysInMonth(month, year))
            day = daysInMonth(month, year);
        return true;
    }
    return false;
}

bool Date::setYear(int y) {
    if (y >= 1900 && y <= 2100) {
        year = y;
        return true;
    }
    return false;
}

void Date::display() const {
    cout << day << "-" << month << "-" << year;
}

string Date::toString() const {
    string dayStr = (day < 10 ? "0" : "") + to_string(day);
    string monthStr = (month < 10 ? "0" : "") + to_string(month);
    return dayStr + "-" + monthStr + "-" + to_string(year);
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

bool Date::operator==(const Date& other) const {
    return (day == other.day && month == other.month && year == other.year);
}

bool Date::operator<(const Date& other) const {
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d.day << "-" << d.month << "-" << d.year;
    return os;
}

