#ifndef DATE_HPP
#define DATE_HPP
#include <string>

// 15/03/2024
class Date
{
public:
    Date(int day, int month, int year);

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    std::string toString() const;

    bool operator<(const Date &other) const;

private:
    static bool isValid(int day, int month, int year);
    static bool isLeapYear(int year);
    static int daysInMonth(int month, int year);

    int day;
    int month;
    int year;
};

#endif