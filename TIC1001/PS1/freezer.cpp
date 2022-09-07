#include <stdio.h>
#include <cmath>

#define FRIDGE_TEMPERATURE -10
#define EXPONENTIAL 2.71828 

using namespace std;

double freezer(int hrs, int mins, int t0, double c) {
    float finalhrs = hrs + mins/60.0;
    float t0float = (float) t0;
    return t0float - (t0float - (-10.0)) * (1.0 - pow(2.71828, -c * finalhrs)); 
}

// main function for your testing. Do not copy into Coursemology
int main(void) {
    double out = freezer(1, 30, 27, 1.5);  // edit the input to test
    printf("Your function output is: %f\n", out);
    return 0;
}