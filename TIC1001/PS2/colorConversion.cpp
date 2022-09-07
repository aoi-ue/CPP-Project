#include <stdio.h>
#include <cmath>

using namespace std;

struct HSL
{
    int hue;
    int sat;
    int lum;
};

float max(float num1, float num2)
{
    float result;

    if (num1 > num2)
    {
        result = num1;
    }
    else
    {
        result = num2;
    }

    return result;
}

float min(float num1, float num2)
{
    float result;

    if (num1 > num2)
    {
        result = num2;
    }
    else
    {
        result = num1;
    }

    return result;
}

// *** Do not edit above this line. ***
// Only copy this function into Coursemology
HSL rgb_to_hsl(int red, int green, int blue)
{
    int hue, sat, lum; // assign the correct values to these variables

    float fred = red / 255.0;
    float fgreen = green / 255.0;
    float fblue = blue / 255.0;

    // Your answer here.
    float maximum = max(max(fred, fgreen), fblue);
    float minimum = min(min(fred, fgreen), fblue);
    float total = maximum + minimum;
    float difference = maximum - minimum;
    float cal = (fred - fgreen) / difference;

    if (maximum == fblue)
    {
        hue = round((4.0 + cal) * 60.0);
        printf("blue is the maxi: %f the mini: %d\n", maximum, hue);
    }
    else if (maximum == fgreen)
    {
        hue = round((2.0 + cal) * 60.0);
        printf("green is the maxi %f\n %f\n", maximum, minimum);
    }
    else
    {
        hue = round(cal * 60.0);
        printf("red is the maxi fred %f\n %f\n", maximum, minimum);
    }

    if (hue < 0)
    {
        hue += 360.0;
    }

    lum = round(((maximum + minimum) / 2.0) * 100.0);

    if (lum > 0.5)
    {
        sat = (difference / total) * 100;
        printf("difference: %f total: %f\n", difference, total);
    }
    else
    {
        sat = difference / (2 - total) * 100;
        printf("difference: %f total: %f\n", difference, total);
    }

    if (maximum == minimum)
    {
        sat = 0;
        hue = 0;
    }

    // *** Do not edit this line. It is to return 3 values together ***
    return (HSL){.hue = hue, .sat = sat, .lum = lum};
}

int main()
{
    // edit these RGB values to test
    int red = 24;
    int green = 98;
    int blue = 118;

    HSL hsl = rgb_to_hsl(red, green, blue);
    printf("The result is Hue:%d, Sat:%d, Lum:%d\n", hsl.hue, hsl.sat, hsl.lum);

    return 0;
}