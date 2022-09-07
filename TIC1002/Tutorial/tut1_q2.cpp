#include <cstdio>
#include <iostream>

using namespace std;

//Defines for Readability
#define M 2
#define P 3
#define N 2

void matmul_one_element(int A[][P], int B[][N], int C[][N],
                        int i, int j);
//Purpose: Perform the matrix multiplication for one element at C[i][j]
//       : C[i][j] = Sum (A[i][k] * B[k][j]), where k = 0...P-1

void matmul(int A[][P], int B[][N], int C[][N]);
//Purpose: Perform matrix multiplication for matrices A x B, result in C

int main()
{
    int matA[M][P] = {
        {1, 2, 3},
        {4, 5, 6}};

    int matB[P][N] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    int matC[M][N] = {{0}}; //just zeroes the whole matrix

    int i, j;

    matmul_one_element(matA, matB, matC, 0, 0);

    // matmul_one_element(matA, matB, matC, 0, 1);	

    // matmul_one_element(matA, matB, matC, 1, 0);	

    // matmul_one_element(matA, matB, matC, 1, 1);

    // matmul(matA, matB, matC);

    // Simply print out the matrix for checking
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << matC[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

void matmul_one_element(int A[][P], int B[][N], int C[][N],
                        int i, int j)
{
    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            for (int k = 0; k < P ; ++k) {
                C[i][j] += (A[i][k] * B[k][j]); 
            }
        }
    }
}

void matmul(int A[][P], int B[][N], int C[][N])
{
}
