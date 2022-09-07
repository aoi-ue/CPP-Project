#include <iostream>
using namespace std;

int sum_odd_n(int n) {
    int i, sum = 0;

    for(i = 1; i <= n; i++) {
        sum += (2 * i) - 1;
    }

    return sum; 
}

int main()
{
    for (int i = 0; i < 6; i++) {
        cout << sum_odd_n(i) << endl;
    }
    return 0;
};