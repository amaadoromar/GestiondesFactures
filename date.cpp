#include "date.h"


Date Date::operator=(Date& assdate)
{
    month = assdate.month;
    day = assdate.day;
    year = assdate.year;

    return *this;
}

Date::Date(int mm, int dd, int yyyy)
{
    month = mm;
    day = dd;
    year = yyyy;
}

Date::Date(long mmddyyyy)
{
    year = int(mmddyyyy / 10000.0);
    month = int((mmddyyyy - year * 10000.0) / 100.0);
    day = int(mmddyyyy - year * 10000.0 - month * 100.0);
}

void Date::swapDate(Date *date1, Date *date2)
{
    Date tempdate;

    tempdate.day = date1->day;
    tempdate.month = date1->month;
    tempdate.year = date1->year;

    date1->day = date2->day;
    date1->month = date2->month;
    date1->year = date2->year;

    date2->day = tempdate.day;
    date2->month = tempdate.month;
    date2->year = tempdate.year;

    return;
}

void Date::Juliandate(Date& gregorian)
{

    long MP, YP, T, JULIANDATE;
    if(gregorian.month <= 2)
    {
        MP = 0;
        YP = gregorian.year - 1;
    }
    else
    {
        MP = int(0.4 * gregorian.month + 2.3);
        YP = gregorian.year;
    }

    T = int(YP / 4) - int(YP / 100) + int(YP / 400);
    JULIANDATE = 365 * gregorian.year + 31 * (gregorian.month - 1) + gregorian.day + T - MP;

    cout << "julian date: " << JULIANDATE << endl;

    return;

}

void OBJ_latestdate(long yyyymmdd, long xxxxbbss)
{
    long a = yyyymmdd;
    long b = xxxxbbss;
    int month, year, day;
    int month2, year2, day2;



    if(a > b){

    year = int(a / 10000.0);
    month = int((a - year * 10000.0) / 100.00);
    day = int(a - year * 10000.0 - month * 100.0);

    cout << endl;
    cout << "\nlatest date: ";
    cout << setfill('0')
         << setw(2) << month << '/'
         << setw(2) << day  << '/'
         << setw(2) << year;
    cout << endl;


    }
    else{
    year2 = int(b / 10000.0);
    month2 = int((b - year2 * 10000.0) / 100.00);
    day2 = int(b - year2 * 10000.0 - month2 * 100.0);

    cout << endl;
    cout << "\nlatest date: ";
    cout << setfill('0')
         << setw(2) << month2 << '/'
         << setw(2) << day2  << '/'
         << setw(2) << year2;
    cout << endl;

    }


    return;
}


void Date::latestDate(long yyyymmdd, long xxxxbbss)
{
    long a = yyyymmdd;
    long b = xxxxbbss;
    int month, year, day;
    int month2, year2, day2;



    if(a > b){

    year = int(a / 10000.0);
    month = int((a - year * 10000.0) / 100.00);
    day = int(a - year * 10000.0 - month * 100.0);

    cout << endl;
    cout << "\nlatest date: ";
    cout << setfill('0')
         << setw(2) << month << '/'
         << setw(2) << day  << '/'
         << setw(2) << year;
    cout << endl;


    }
    else{
    year2 = int(b / 10000.0);
    month2 = int((b - year2 * 10000.0) / 100.00);
    day2 = int(b - year2 * 10000.0 - month2 * 100.0);

    cout << endl;
    cout << "\nlatest date: ";
    cout << setfill('0')
         << setw(2) << month2 << '/'
         << setw(2) << day2  << '/'
         << setw(2) << year2;
    cout << endl;

    }


    return;
}


void Date::dayofWeek()
{
    int century, setyear, time, dayweek;
    string days[7] = {"saturday", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday"};

    if(month < 3)
    {
        month = month + 12;
        year = year - 1;
    }
    else
    {
        century = int(year / 100);
        setyear = year % 100;
        time = day + int(26 *(month + 1) / 10) + setyear + int(setyear / 4) *
               int(century / 4) - 2 * century;
        dayweek = time % 7;
    }
    if(dayweek < 0)
    {
        dayweek = dayweek + 7;
    }

    for(int a = 0; a < 7; a++)
    {
        if(dayweek == a)
        {
            cout << "the day is " << days[a] << endl;
        }
    }
}

void Date::leapyr()
{
    leapyear = year % 4;
    if(leapyear == 0)
        cout << "\nthis is a leap year: " << year;
    else
        cout << "\nnot a leap year: " << year;

    return;
}

int Date::convertDate(int month, int day, int year)
{
    datesort = (year * 10000) + (month * 100) + day;
    return datesort;
}

long Date::setDate(int mm, int dd, int yyyy)
{
    long longdate;

    month = mm;
    day = dd;
    year = yyyy;

    longdate = convertDate(month, day, year);

    return longdate;
}

void Date::showDate()
{

    cout << setfill('0')
         << setw(2) << month << '/'
         << setw(2) << day  << '/'
         << setw(2) << year % 100;
    cout << endl;

    return;
}

void Date::nextDay()
{
    day++;
    if(day == 32)
    {
        day = day - 31;
        month++;
        if(month == 13)
        {
            month = month - 12;
            year++;

        }
    }
    else
    {
        month = month;
        year = year;
    }
}
