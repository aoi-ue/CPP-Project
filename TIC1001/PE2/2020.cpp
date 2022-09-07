#include <iostream>
#include <vector>
#include "lib/pe2-functions.h"  /* given functions */

using namespace std;

/* Part A */
int sow(vector<int> & row, int pit) {
    /* Your answer here */
    int store = 0; 
    int total_seed = row[pit]; 
    row[pit] = 0; 
    for (int seeds = total_seed - 1; seeds > 0; seeds--)
    { 
        pit-=1;
        if (pit < 0) 
        {
            store += 1; 
            pit = row.size() - 1;
            row[pit] += 1; 
        }
        else
        {
            row[pit] += 1; 
        }
    }
    return store;
}


/* Part B */ 
vector<int> slice(const vector<int> v, int start, int end) {
    /* Your answer here */

    vector<int> output;

    for(int i = start; i < end; i++)
    {
        output.push_back(v[i]);  
    }
    return output;
}


/* Part C */
// int sow2(vector<int> & our_row, vector<int> & their_row, int pit) {
//     /* Your answer here */
//     return 0;
// }


/*** SAMPLE TESTS ***/

/* Part A Test Driver */
void test_sow(vector<int> row, int pit) {
    cout << "-- Part A Test --" << endl;
    cout << "Before: " << row << endl;
    cout << "Return: " << sow(row, pit) << endl;
    cout << "After:  " << row << endl << endl;
}

/* Part C Test Driver */
// void test_sow2(vector<int> our, vector<int> opp, int pit) {
//     cout << "-- Part C Test --" << endl;
//     cout << "Before: " << opp << endl;
//     cout << "        " << our << endl;
//     cout << "Return: " << sow2(our, opp, pit) << endl;
//     cout << "After:  " << opp << endl;
//     cout << "        " << our << endl << endl;
// }

int main() {
    /* Part A Sample Tests */
    test_sow({1, 5, 4, 4, 4, 4}, 1);
    test_sow({0, 1, 2, 3, 4, 5}, 5);
    test_sow({7, 3, 5, 1}, 0);

    /* Part B Sample Tests */
    // cout << slice({1, 2, 3, 4, 5, 6}, 2, 5) << endl;
    // cout << slice({1, 2, 3, 4, 5, 6}, 0, 6) << endl;
    // cout << slice({1, 2, 3, 4, 5, 6}, 3, 4)  << endl;

    // /* Part C Sample Tests */
    // test_sow2({4, 10, 4, 4, 4, 4}, {4, 4, 4, 4, 4, 4}, 1);
    // test_sow2({9, 8, 7}, {3, 4, 5}, 0);
    // return 0;
}