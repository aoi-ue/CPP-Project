int fibonacci_m(int N, int known_result[])
{
    //Do not remove the following line
    __call_count++;

    //Put your code below
   
    //Put your code below
    if (N <= 2)
    {
        known_result[N] = 1;
        return 1;
    }

    if (known_result[N] != 0)
        return known_result[N];

    else
    {
        // store the computed value of fib(n)
        // in an array term at index n to
        // so that it does not needs to be
        // precomputed again
        int left = known_result[N - 1] != 0 ? known_result[N - 1] : fibonacci_m(N - 1, known_result);
        int right = known_result[N - 2] != 0 ? known_result[N -2] : fibonacci_m(N - 2, known_result);

        known_result[N] = left + right;

    }
    return known_result[N];

}
