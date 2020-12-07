#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <QTextStream>
#include <ctime>

class Date
{
private:

    int _day;
    int _month;
    int _year;

    int _hours;
    int _mins;
    int _secs;



public:
    Date();
    explicit Date(int day, int month, int year,
    int secs, int mins, int hours) : _day(day), _month(month), _year(year),
        _secs(secs), _mins(mins), _hours(hours) {}

    int day() const;
    void setDay(const int &day);
    int month() const;
    void setMonth(const int &month);
    int year() const;
    void setYear(const int &year);
    int secs() const;
    void setSecs(const int &secs);
    int mins() const;
    void setMins(const int &mins);
    int hours() const;
    void setHours(const int &hours);
};

bool operator > (Date a, Date b);
bool operator < (Date a, Date b);
bool operator >= (Date a, Date b);
bool operator <= (Date a, Date b);
bool operator == (Date a, Date b);
bool operator != (Date a, Date b);


#endif // DATE_H
