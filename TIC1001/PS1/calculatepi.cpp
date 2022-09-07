#include <stdio.h>

double calculatePi(int nTerms)
{
    //The corrected function here
    double pi = 0;
    int step = 1; 
    for (int i = 1; i <= nTerms; i++)
    {
        if (i % 2 == 0)
        {
            pi -= 4.0 / step;
            printf("pi value being minus %f\n", pi);
        }
        else 
        {
            pi += 4.0 / step; 
            printf("pi value being added %f\n", pi);
        }
        printf("step up %d\n", step);
        step += 2; 

    }
    return pi;
}

int main()
{
    calculatePi(5);
}