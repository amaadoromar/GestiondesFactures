#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;


class Date
{
    friend void OBJ_latestdate(long, long);

private:
    int month;
    int day;
    int year;
    int datesort;
    int leapyear;
    int latestdate;
    int month2;
    int day2;
    int year2;
public:
    Date(int = 7, int = 4, int = 2012);
    Date(long);
    long setDate(int, int ,int);
    int convertDate(int, int, int);
    void showDate();
    void leapyr();
    void dayofWeek();
    void nextDay();
    void backDay();
    void latestDate(long, long);
    void swapDate(Date *, Date *);
    void Juliandate(Date&);
    Date operator=(Date&);
};
