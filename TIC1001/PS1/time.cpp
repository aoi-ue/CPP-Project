#include <iostream>
using namespace std;
// Edit your answers here
int hrs_elapsed(int h0, int m0, int s0, int h1, int m1, int s1)
{
    int fh = h1 - h0;
    int fm = m1 - m0;
    int fs = s1 - s0;

    if (fs < 0)
    {
        fm -= 1;
        fs += 60;
    }

    if (fm < 0)
    {
        fh -= 1;
        fm += 60;
    }

    return fh;
}

int mins_elapsed(int h0, int m0, int s0, int h1, int m1, int s1)
{
    int fm = m1 - m0;
    int fs = s1 - s0;

    if (fs < 0)
    {
        fm -= 1;
    }

    if (fm < 0)
    {
        return fm + 60;
    }
    else
    {
        return fm;
    }
}

int secs_elapsed(int h0, int m0, int s0, int h1, int m1, int s1)
{
    int fs = s1 - s0;

    if (fs < 0)
    {
        return fs + 60;
    }
    else
    {
        return fs;
    }
}

void time_elapsed(int h1, int m1, int s1, int h2, int m2, int s2)
{
    // edit the input to test
    int h = hrs_elapsed(h1, m1, s1, h2, m2, s2);
    int m = mins_elapsed(h1, m1, s1, h2, m2, s2);
    int s = secs_elapsed(h1, m1, s1, h2, m2, s2);

    printf("Your function output is h: %d, m: %d, s: %d\n", h, m, s);
}

// main function for your testing. Do not copy into Coursemology
int main(void)
{

    // time_elapsed(12, 30, 40, 13, 30, 50);
    // time_elapsed(12, 30, 0, 12, 50, 0);
    // time_elapsed(12, 30, 0, 13, 50, 0);
    // time_elapsed(12, 30, 0, 12, 50, 0);
    // time_elapsed(12, 30, 0, 15, 30, 0);

    printf("%d", hrs_elapsed(12, 30, 40, 13, 30, 50));
    printf("%d", mins_elapsed(12, 20, 30, 13, 30, 50));
    printf("%d", secs_elapsed(12, 20, 30, 13, 30, 50));

    return 0;
}
