#include <cstdio>
#include <iostream>

using namespace std;

struct SResult {
   string studentID;   //student id is a string with "A1234" format
   int score;       //score received by students
};

void counting_sort(SResult scoreArr[], int N, SResult final[])
{
    //Note: For clarity, we use both freq[] and cfreq[]
    //      They can be combined, i.e. only 1 array if you want
    int freq[11] = {0}, cfreq[11] = {0};
    int i, curScore;

    //1. Compute Frquency
    for (i = 0; i < N; i++){
        freq[scoreArr[i].score]++;
    }

    // 2. Compute Cumulative Frequency
    cfreq[0] = freq[0];
    for (i = 1; i < 11; i++){
        cfreq[i] = cfreq[i-1] + freq[i];  
    }

//3. Produce Final Position
    for (i = N-1; i >= 0; i--){
        //Note the next two lines can be combined as:
        // final[ cfreq[ score[i] ] - 1 ] = score[i];
        curScore = scoreArr[i].score;
        final[cfreq[ curScore ] - 1].score = scoreArr[i].score;
        // final[cfreq[ curScore ] - 1].studentID = scoreArr[i].studentID;
        cfreq[curScore]--;
    }
}

int main()
{
    // int sample[] = {10, 5, 7, 3, 5, 7, 7, 9, 2, 5, 7, 3};
    // int sorted[12] = {0};
    int i;

    SResult result[] = {{"2", 10}, {"1", 20}}; 

    SResult sorted[2] = {}; 

    counting_sort(result, 2, sorted);

    for (i = 0; i < 12; i++){
        // cout << result[i].studentID << " ";
        // cout << "kolek" << endl; 
        cout << sorted[i].score << " ";

    }
    cout << endl;

    return 0;
}
