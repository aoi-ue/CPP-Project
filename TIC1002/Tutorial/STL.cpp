#include<iostream>
#include <vector>

using namespace std;

template <typename T>

// vector<T> reverse(vector<T> v) {
//     vector<T> newV; 

//     for (int i = v.size() - 1; i >= 0; i--) {
//         newV.push_back(v[i]); 
//     }
//     return newV; 
// }

void reverse(vector<T> v) {
    for (int i = v.size() - 1; i >= 0; i--) {
        cout << v[i]; 
    }
}


int main() {
    vector<int> numofvec {1, 3, 4, 7, 8, 9};

    // vector<int> newVec = reverse(numofvec); 
    reverse(numofvec);

    // for(int i = 0; i < newVec.size() ; i++){
    //     cout << newVec[i]; 
    // }

    return 0; 
}