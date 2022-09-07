#include <iostream>
#include <string>
#include <vector>

using namespace std;

//--------//
// TASK 1 //
//--------//

char shift_char(char c, int n)
{
    if (c >= 'A' && c <= 'Z')
    {
        // c = 'A' + (c - 'A' + n) % 26;
        c = ((c - 'A') + n) % 26 + 'A';
        if (c < 'A') {
            c += 26;
        } 
        if (c > 'Z') {
            c -= 26; 
        }
    }

    if (c >= 'a' && c <= 'z')
    {
        // c = 'a' + (c - 'a' + n) % 26;
        c = ((c - 'a') + n) % 26 + 'a';
        if (c < 'a') {
            c += 26;
        } 
        if (c > 'z') {
            c -= 26; 
        }
    }
    return c;
}

string &rotate(string &s, int n)
{
    int i;
    string s1;
    for (i = 0; i < s.size(); i++)
    {
        s1.push_back(s[(s.size() + i + n) % s.size()]);
    }

    s.clear();
    s.append(s1);

    return s;
}

//--------//
// TASK 2 //
//--------//

string &caeser(string &s, int n)
{
    int i;
    string s1;
    for (i = 0; i <= s.size(); i++)
    {
        s[i] = shift_char(s[i], n);
    }
    return s;
}

//--------//
// TASK 3 //
//--------//

string &substitute(string &s, const string key)
{
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = key[s[i] - 65] - 32;
        }
        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = key[s[i] - 97];
        }
    }
    return s;
}

// einnd
// hello

string &unsubstitute(string &s, const string key)
{
    string alp = "abcdefghijklmnopqrstuvwxyz";
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            int alpha_index = key.find(s[i] + 32);
            s[i] = (char)(65 + alpha_index);
        }
        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = alp[key.find(s[i])];
        }
    }
    return s;
}

//--------//
// TASK 4 //
//--------//

string &vigenere(string &s, vector<int> key)
{
    int j = 0;
    for (int i = 0; j < s.size(); i = (i + 1) % key.size(), j++)
    {
        s[j] = shift_char(s[j], key[i]);
    }

    return s;
}

string &unvigenere(string &s, vector<int> key)
{
    int j = 0;
    for (int i = 0; j < s.size(); i = (i + 1) % key.size(), j++)
    {
        s[j] = shift_char(s[j], (int)(-key[i]));
    }

    return s;
}

//--------//
// TASK 5 //
//--------//

void freq(string s)
{
    int counts[26] = {0};

    int i;
    size_t len = s.length();

    for (i = 0; i < len; i++)
    {
        // Just in order that we don't shout ourselves in the foot
        char c = s[i];
        if (!isalpha(c))
            continue;

        counts[(int)(tolower(c) - 'a')]++;
    }

    for (i = 0; i < 26; i++)
    {
        printf("%c:%d ", i +'a', counts[i]);
    }
}

// Main Function
int main(void)
{
    string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit!";
    string key = "phqgiumeaylnofdxjkrcvstzwb";
    vector<int> vkey = {7, 5, -6, 22, -13, 6};

    // Uncomment to test the different functions
    // cout << shift_char('l', 6) << endl;
    // cout << shift_char('c', -2) << endl;
    // cout << shift_char('g', 20) << endl;
    // cout << shift_char('\\', 20) << endl;

    // cout << rotate(text, 3) << endl;
    // cout << rotate(text, -3) << endl;

    // cout << caeser(text, 3) << endl;
    // cout << caeser(text, -3) << endl;

    // cout << substitute(text, key) << endl;
    // cout << unsubstitute(test, key) << endl;

    string test = "bzbzBZBZayayAYAY";
    string testrev = "bzbzBZBZayayAYAY";
    cout << vigenere(test, vkey) << endl;
    cout << unvigenere(testrev, vkey) << endl;

    // freq(text);

    return 0;
}