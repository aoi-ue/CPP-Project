#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

/******************************************
Part A. Date Related Functions
******************************************/
struct Date
{
    int year;
    int month;
    int day;
};

void make_date(Date &newDate,
               int year, int month, int day)
{
    newDate.year = year;
    newDate.month = month;
    newDate.day = day;
}

int compare_date(Date &dateA, Date &dateB)
{
    if (dateA.year > dateB.year)
    {
        return 1;
    }
    else if (dateA.year < dateB.year)
    {
        return -1;
    }
    else
    {
        return 0;
    }

    // return 0; //remember to change
}

/******************************************
Part B. Time Related Functions
******************************************/
struct Time
{
    int hour;
    int minute;
};

void make_time(Time &newTime, int hour, int minute)
{
    newTime.hour = hour;
    newTime.minute = minute;
}

int compare_time(Time &timeA, Time &timeB)
{
    if (timeA.hour > timeB.hour)
    {
        return 1;
    }
    else if (timeA.hour < timeB.hour)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

/******************************************
Part C. Appointmnet Related Functions
******************************************/

struct Appointment
{
    string description;
    struct Date date;
    struct Time startTime;
    struct Time endTime;
};

void make_appointment(Appointment &newApt,
                      string description,
                      int year, int month, int day,
                      int startHour, int startMinute,
                      int endHour, int endMinute)
{
    newApt.description = description;
    newApt.date.year = year;
    newApt.date.month = month;
    newApt.date.day = day;
    newApt.startTime.hour = startHour;
    newApt.startTime.minute = startMinute;
    newApt.endTime.hour = endHour;
    newApt.endTime.minute = endMinute;
}

bool time_check(int early, int late)
{
    if (early < late)
    {
        return early > late;
    }
    if (early > late)
    {
        return early < late;
    }

    return false;
}

bool has_conflict(Appointment &aptA, Appointment &aptB)
{
    if (aptA.date.day == aptB.date.day && aptA.date.month == aptB.date.month && aptA.date.year == aptB.date.year)
    {
        cout << "check"; 
        if ( aptA.endTime.hour >= aptB.startTime.hour ) 
        {
            return (
            time_check(aptA.startTime.minute, aptB.endTime.minute) || 
            time_check(aptA.endTime.minute, aptB.startTime.minute) ||
            time_check(aptB.endTime.minute, aptA.startTime.minute) || 
            time_check(aptB.startTime.minute, aptA.endTime.minute) ); 
        }
        // if (aptA.startTime.hour >= aptB.startTime.hour && aptA.startTime.minute < aptB.startTime.minute)
        // {
        //     cout << "case 1";
        //     return true;
        // }

        // if (aptA.endTime.hour >= aptB.startTime.hour && aptA.endTime.minute > aptB.startTime.minute)
        // {
        //     cout << "case 2";
        //     return true;
        // }

        // if (aptA.startTime.hour <= aptB.endTime.hour && aptA.startTime.minute < aptB.endTime.minute)
        // {
        //     cout << "case 3";
        //     return true;
        // }

        // if (aptA.endTime.hour >= aptB.endTime.hour && aptA.endTime.minute > aptB.endTime.minute)
        // {
        //     cout << "case 4";
        //     return true;
        // }

        // if (aptA.startTime.minute >= aptB.startTime.minute && aptA.startTime.minute > aptB.endTime.minute)
        // {
        //     cout << "case 5";
        //     return true;
        // }
    }
    return false; 
}

/***********************************************************
   Main function
***********************************************************/

int main()
{
    //Comment / modify the following statements to test
    //Note: you should test beyond these cases
    //Note2: you should consider implement additional useful helper
    //       functions

    /*****************
     *Testing Part A.*
     *****************/

    // Date dateOne, dateTwo;
    // make_date(dateOne, 2018, 1, 23);
    // make_date(dateTwo, 2018, 1, 23);

    // //Should be 0 for the sample test values above
    // cout << "Date compare result = "
    //     << compare_date(dateOne, dateTwo) << endl;

    /*****************
     *Testing Part B.*
     *****************/

    // Time timeOne, timeTwo;
    // make_time(timeOne, 11, 30);
    // make_time(timeTwo,11, 30);

    // //Should be -1 for the sample test values above
    // cout << "Time compare result = "
    //     << compare_time(timeOne, timeTwo) << endl;

    /*****************
     *Testing Part C.*
     *****************/
    Appointment aptOne, aptTwo;
    make_appointment(aptOne, "Appointment One",
                     2018, 1, 23, 11, 30, 12, 45);

    make_appointment(aptTwo, "Appointment Two",
                     2018, 1, 23, 10, 30, 11, 31);

    //Should be Fine for the sample test values above
    //Make sure you test all possibilities
    if (has_conflict(aptOne, aptTwo))
    {
        cout << "Appointments CLASH!\n";
    }
    else
    {
        cout << "Appointments are FINE!\n";
    }
    return 0;
}
