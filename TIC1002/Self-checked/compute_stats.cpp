#include <iostream> 
#include <cstdio>
#include <cmath>

using namespace std;

void compute_stats(int array[], int size, double* average, double* stddev)
{
    int i; 
    double sum = 0; 
    for (i = 0; i < size; i++)
    {
       sum += array[i]; 
    }
    *average = sum/size; 

    for(i = 0; i < size; i++) {
        double diff = array[i] - *average; 
        *stddev += (diff * diff);
    }

    *stddev = sqrt(*stddev / (size - 1)); 
}

// void compute_stats(int array[], int size, double *average,
//                    double *stddev)
// {
//     int i; 
//     double sum = 0; 
//     for (i = 0; i < size; i++)
//     {
//        sum += array[i]; 
//     }
//     *average = sum/size; 

//     for(i = 0; i < size; i++) {
//         *stddev += pow(array[i] - *average, 2);
//     }
//     cout << sqrt(*stddev/size) << endl; 

//     *stddev = sqrt(*stddev / size); 
// }

int main()
{
    int sample[] = {1, 2, 3, 4, 5, 6, 7, 8};
    //int sample[] = {727, 1086, 1091, 1361, 1490, 1956};
    double avg, stdd;

    compute_stats(sample, 8, &avg, &stdd);

    //Using C-Style printf for convenience
    printf("Average = %.4f, Std. Deviation = %.4f\n", avg, stdd);

    return 0;
}
