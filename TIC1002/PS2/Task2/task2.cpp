#include <iostream>
#include <cstdio>

using namespace std;

// int power(int num, int exp) {
//     int result = 1;
//     for (int i = 1; i <= exp; i++) {
//         result = result * num;
//     }
//     return result;
// }

// int polynomial(int xValue, int termArray[], int nTerm)
// {
//     int result = 0;
//     for (int i = 1; i <= nTerm; i++)
//     {
//         result += termArray[i - 1] * power(xValue, i);
//     }
//     return result;
// }

int power(int num, int exp)
{
    if (exp != 0)
        return (num * power(num, exp - 1));
    else
        return 1;
}

int polynomial(int xValue, int termArray[], int nTerm)
{
    if (nTerm == 0)
    {
        return termArray[nTerm - 1];
    }
    return termArray[nTerm - 1] + (xValue * polynomial(xValue, termArray, nTerm - 1));
}

void printPolynomial(int termArray[], int nTerm)
{
    int i;

    for (i = 0; i < nTerm; i++)
    {
        if (i > 0)
        {
            cout << "+ ";
        }
        cout << termArray[i];
        switch (i)
        {
        case 0:
            cout << "X";
            break;
        default:
            cout << "X^" << (i + 1);
        }
        cout << " ";
    }

    cout << endl;
}

int main()
{

    int poly[] = {3, 2, 1};

    //Test cases A
    printPolynomial(poly, 3);
    cout << "When X = 2, = " << polynomial(2, poly, 3) << endl;
    cout << "When X = 3, = " << polynomial(3, poly, 3) << endl
         << endl;

    //Test cases B
    // int poly2[] = {7, 5, 3, 2};
    // printPolynomial(poly2, 4);
    // cout << "When X = 11, = " << polynomial(11, poly2, 4) << endl;
    // cout << "When X = 13, = " << polynomial(13, poly2, 4) << endl;

    return 0;
}
