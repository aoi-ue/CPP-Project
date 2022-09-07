#include <stdio.h>

bool morning_surchage(int time)
{
    return (6 * 60 <= time) && (time <= 8 * 60 + 59);
}

bool evening_surchage(int time)
{
    return (18 * 60 < time) && (time <= 23 * 60 + 59);
}

bool midnight_surchage(int time)
{
    return (0 * 60 <= time) && (time <= 5 * 60 + 59);
}

// 1 - 5 dates @ 6 * 60 till 8 * 60 + 59 is *1.25
// 1 - 7 dates @ 18 * 60 till 11 * 60 + 59 is *1.25
// 1 - 7 dates @ 0 * 60 till 5 * 60 + 59 is *1.5
float surcharge(int day, int time)
{
    if (day <= 7)
    {
        if (evening_surchage(time) | (day <= 5 && morning_surchage(time)))
        {
            printf("1.25 surchage\n");
            return 1.25;
        }
        else if (midnight_surchage(time))
        {
            printf("1.5 surchage\n");
            return 1.5;
        }
        else
        {
            printf("no surchage\n");
            return 1;
        }
    }
    return 0;
}

float taxi_fare(int weekday, int start_time, int duration, int distance)
{
    // your code here
    printf("start min after midnight: %.3d min\n", start_time);
    float distance_per_min = (50.0 / 6) * 60;
    printf("speed @: %.3f m/min\n", distance_per_min);

    int total_time_taken = distance / distance_per_min;
    printf("total time taken: %.3d min\n", total_time_taken);

    int end_time = start_time + total_time_taken;
    printf("ended min after midnight: %.3d min\n", end_time);

    int after_10k_distance = distance - 10000;

    double calculated = 3.4;

    // without surcharge
    if (distance <= 1000)
    {
        printf("ended before or at 1KM mark\n");
        calculated *= surcharge(weekday, start_time);
    }
    else
    {
        // for loop to add 0.22 every 400 m before 10km and every 350 after 10km
        if (distance < 10000)
        {
            calculated *= surcharge(weekday, start_time);
            printf("starting meter: %f\n", calculated);

            printf("from 1km to 10km: \n");
            float now_time = start_time + (1000 / distance_per_min);

            for (float d = 1000; d <= distance; d += 400.0)
            {
                now_time += (400 / distance_per_min);
                printf("time now: %f\n", now_time);

                calculated += 0.22 * surcharge(weekday, now_time);
                printf("meter now: %f\n", calculated);

                printf("distance now: %f\n", d);
                // for (float t = start_time - (1000/distance_per_min); t <= end_time ; t += 1)
                // {
                //     printf("time now %f\n", t);
                //     surcharge(weekday, t, calculated);
                // }
                printf("next loop\n");
            }
        }

        if (distance > 10000)
        {
            calculated *= surcharge(weekday, start_time);
            printf("starting meter: %f\n", calculated);

            printf("from 1km to 10km: \n");
            float now_time = start_time + (1000 / distance_per_min);

            for (float d = 1400; d <= distance - after_10k_distance; d += 400.0)
            {
                now_time += (400 / distance_per_min);
                printf("time now: %f\n", now_time);

                calculated += 0.22 * surcharge(weekday, now_time);
                printf("meter now: %f\n", calculated);

                printf("distance now: %f\n", d);
                // for (float t = start_time - (1000/distance_per_min); t <= end_time ; t += 1)
                // {
                //     printf("time now %f\n", t);
                //     surcharge(weekday, t, calculated);
                // }
                printf("next loop\n");
            }

            printf("after 10km: \n");

            for (float d = 10000; d <= distance; d += 350)
            {
                printf("distance now: %f meter \n", d);

                float now_time = start_time + (10000 / distance_per_min);

                now_time += (350 / distance_per_min);

                calculated += 0.22 * surcharge(weekday, now_time);

                printf("time now: %f min\n", now_time);

                printf("meter now: $%f\n", calculated);

                // for (float t = start_time - (1000/distance_per_min); t <= end_time ; t += 1)
                // {
                //     printf("time now %f\n", t);
                //     surcharge(weekday, t, calculated);
                // }
                printf("next loop\n");
            }
        }
    }
    return calculated;
}

int main(void)
{
    // You may change the inputs to the function for testing
    // double example1 = taxi_fare(1, 17 * 60 + 59, 6, 1000);
    // printf("total to be $3.400: $%.3f\n", example1);
    // printf("\n");

    // double example2 = taxi_fare(1, 17 * 60 + 57, 6, 2000);
    // printf("total to be $4.115: $%.3f\n", example2);
    // printf("\n");

    double example3 = taxi_fare(1, 5 * 60 + 50, 6, 15000);
    printf("total to be $15.825: $%.3f", example3);
    printf("\n");

    // double example4 = taxi_fare(7, 8 * 60 + 57, 6, 1000);
    // printf("total to be $3.400: $%.3f", example4);
    // printf("\n");

    // double example5 = taxi_fare(1, 8 * 60 + 57, 6, 1000);
    // printf("total to be $4.250: $%.3f", example5);

    return 0;
}