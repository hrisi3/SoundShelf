#include "Date.hpp"
#include "exceptions/LibraryExceptions.hpp"

Date::Date(int day, int month, int year)
    : day(day), month(month), year(year)
{
    if (!isValid(day, month, year))
    {
        throw InvalidDateException("Invalid date: " + std::to_string(day) +
                                   "/" + std::to_string(month) + "/" +
                                   std::to_string(year));
    }
}

std::string Date::toString() const
{
    auto pad = [](int value)
    {
        return (value < 10 ? "0" : "") + std::to_string(value);
    };

    return pad(day) + "/" + pad(month) + "/" + std::to_string(year);
}

bool Date::operator<(const Date &other) const
{
    if(year != other.year)
        return year < other.year;
    if(month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Date::isValid(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > daysInMonth(month, year))
        return false;
    return true;
}

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year)
{
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}
