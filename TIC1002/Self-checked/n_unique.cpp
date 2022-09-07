#include <iostream>
#include <string>

using namespace std;

void n_unique(const string& input, string& result, int nCopy)
{
    int alp_count[26] = {};

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > 96 && input[i] < 123)
        {
            if (alp_count[input[i] - 97] < nCopy)
            {
                result.push_back(input[i]); 
                alp_count[input[i] - 97]++;
            }
        } else {
            result.push_back(input[i]); 
        }
    }
}


int main()
{
    string sample = "abcdef!!abc, cba defa bcaba.";
    string result;

    // n_unique(sample, result, 1);
    // cout << "NCopy = 1, Result = " << result << endl;

    n_unique(sample, result, 2);
    cout << "NCopy = 2, Result = " << result << endl;

    // n_unique(sample, result, 3);
    // cout << "NCopy = 3, Result = " << result << endl;

    // n_unique(sample, result, 4);
    // cout << "NCopy = 4, Result = " << result << endl;

    // n_unique("!!!*&%^ #$##$$!!", result, 2);
    // cout << "NCopy = 2, Result = " << result << endl;

    return 0;
}
