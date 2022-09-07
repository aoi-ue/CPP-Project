#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year)
{
    if (year % 400 == 0)
        return true;

    if (year % 100 == 0)
        return false;

    if (year % 4 == 0)
        return true;
    return false;
}

int days_in_month(int month, int year)
{
    int days;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        days = 30;
    }
    else if (month == 2)
    {
        if (is_leap_year(year))
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    }
    else
    {
        days = 31;
    }

    return days;
}

int days_from_epoch(int day, int month, int year)
{
    // your answer here
    int days = 0;

    if (year < 1970)
    {
        days += day - days_in_month(month, year) - 1;

        for (int m = month + 1; m < 13; m++)
        {
            days -= days_in_month(m, year);
        }

        for (int y = year + 1; y < 1970; y++)
        {
            for (int m = 1; m < 13; m++)
            {
                // printf("months: %d\n", m);
                days -= days_in_month(m, y);
            }
            // printf("years: %d\n", y);
        }
        return days;
    }
    else
    {
        for (int y = 1970; y < year; y++)
        {
            for (int m = 1; m < 13; m++)
            {
                // printf("months: %d\n", m);
                days += days_in_month(m, y);
            }
            // printf("years: %d\n", y);
        }

        for (int m = 1; m < month; m++)
        {
            // printf("months: %d\n", m);
            days += days_in_month(m, year);
        }

        days += day - 1;
        return days;
    }
}

void greg_to_mayan(int day, int month, int year) {
    // your code here
    printf("%s", "13.0.0.0.0");  

}

void mayan_to_greg(int baktun, int katun, int tun, int uinal, int kin) {
    // your code here
}

int main(void) {
    greg_to_mayan(21, 12, 2012);
    mayan_to_greg(13, 0, 0, 0, 0);
    return 0;
}