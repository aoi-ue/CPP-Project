#include <stdio.h>
#include <cmath>

using namespace std;

// Edit your answer here
int ip_octet(int b)
{
    int m = 0;
    int l = 0;
    int d = 0;

    while (b != 0)
    {
        d = b % 10;
        d *= pow(2, l++);
        printf
        b /= 10;

        m += d;
    }
    return m;
}

// main function for your testing. Do not copy into Coursemology
int main(void)
{
    int out = ip_octet(11001001); // edit the input to test
    printf("Your function output is: %d\n", out);

    return 0;
}
