#include <stdio.h>

// a.
int factorial(int n)
{
    // your answer here
    if (n < 1)
        return 1;
    return n * factorial(n - 1);
}

/* b. 
What happens to your function when n >= 13? Explain why.
(Put your answer within the comments)
Answer: 
the value from the function is lower than calculated. exceeded 32bit of bit memory size. 
*/

// c.

int choose(int n, int k)
{
    // your answer here
    if (n <= 0 || n > 30 || k < 0 || k > n)
        return 0;

    if (k == 0)
        return 1;
    if (k == 1)
        return n;

    double final_n = 1;
    double final_k = 1;
    int final_d = 1;
    int difference = n - k;

    if (difference >= (n / 2) - 1)
    {
        for (; k > 0; k--)
        {
            if (n != difference)
            {
                final_n *= n;
            }
            n--;
            difference--;
            final_k *= k;

        }
        return (double)(final_n / final_k);
    }
    else
    {
        for (; difference > 0; difference--)
        {
            if (n != k)
            {
                final_n *= n;
            }
            n--;
            k--;
            final_d *= difference;
        }
        return (double)(final_n / final_d);
    }
}

/* d. 
Are you able to make use of the factorial function in choose? Explain why.
(Put your answer within the comments)
Answer: 
unable, as the max k value allow is 12.  
*/

// e.
void pascal_triangle(int row)
{
    // your code here
    int i;
    for (i = 0; i <= row; i++)
    {
        printf("%d ", choose(row, i));
    }
}


int main()
{
    // printf("Factorial %d\n" , factorial(12));
    // printf("Choose %d\n", choose(15, 11));
    // printf("Choose %d\n" , choose(29, 7));
    pascal_triangle(29);
}
