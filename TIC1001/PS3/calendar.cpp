/*************************
 * Problem Set 3: Task 2 *
 *************************
 
Make sure you have answered ALL 
the questions in this task.   */

#include <stdio.h>
#include <stdbool.h>

// a.
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

// b.
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

// c.
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

// d.
int day_of_week(int day, int month, int year)
{
    // your answer here
    int days = (days_from_epoch(day, month, year) % 7) + 4;

    if (days > 6)
    {
        days -= 7;
    }
    return days;
}

// e.
void display_month(int month, int year)
{
    // your code here
    int days = days_in_month(month, year);
    int days_decre = days;

    printf("  S  M  T  W  T  F  S\n");

    int start = day_of_week(1, month, year);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            int cell = (i * 7) + j;

            if (cell < start)
            {
                printf("   ");
            }
            if (cell >= start)
            {
                cell -= start - 1;
                printf("%3d", cell);
                days_decre--;
                if (days_decre <= 0)
                    break;
            }
        }
        if (days_decre <= 0)
            break;
        printf("\n");
    }
}

int main()
{
    // printf("leap: %d", is_leap_year(401));
    // printf("leap: %d", days_in_month(9, 2017));
    // printf("leap: %d", days_in_month(8, 1965));
    // printf("epoch: %d", days_from_epoch(30, 1, 1));
    for (int i = 1; i < 13; i++)
    {
        printf("%dth: \n", i);
        display_month(i, 2017);
    }
}