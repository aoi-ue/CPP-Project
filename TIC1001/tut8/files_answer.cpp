#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <stdio.h>

using namespace std;

int count_alpha(istream &ins)
{
    int count = 0, c;
    while (!ins.eof())
    {
        c = ins.get();
        if (('a' <= c && c <= 'z') ||
            ('A' <= c && c <= 'Z'))
            count++;
    }
    return count;
}

int count_words(istream &ins)
{
    int count = 0;
    string s;
    // using this instead as !ins.eof() flag is only set after the end of file has been read
    while (ins >> s)
    {
        count++;
    }
    return count;
}

int count_sentences(istream &ins)
{
    int count = 0;
    string word;
    // Reading each word by word
    while (ins >> word)
    {
        if (word[word.size() - 1] == '.')
        {
            count++;
        }
    }
    return count;
}

// Captialize every lower case letter
void to_upper(ifstream &ins, ostream &os)
{
    char c;
    while (ins.get(c))
    {
        if ('a' <= c && c <= 'z')
            os.put(c - 32);
        else
            os.put(c);
    }
}

// Captialize first letter of every word
// Idea is to use a flag to check if we are
// at the start of a word.
void to_title_case(istream &ins, ostream &os)
{
    bool cap = true;
    char c;
    while (ins.get(c))
    {
        if (isspace(c))
        { // isspace is found in ctype.h
            cap = true;
        }
        else if (cap)
        {
            if ('a' <= c && c <= 'z')
            {
                c -= 32;
            }
            cap = false;
        }
        os.put(c);
    }
}

// Reverse each line. Assume that line endings are '\n'
void reverse(istream &is, ostream &os)
{
    string sen;
    while (getline(is, sen))
    {
        int n = sen.length();
        // swap characters
        for (int i = 0; i < n / 2; i++)
        {
            swap(sen[i], sen[n - i - 1]);
        }
        os << sen << endl;
    }
}

// Captialise first letter of each sentence
// Use the same technique as title casing of
// using a flag to check start of sentence.
// takes in streams
void to_sentence_case(istream &ins, ostream &os)
{
    char c;
    bool sentence = true;
    while (ins.get(c))
    {
        if (!isspace(c) && sentence)
        {
            if (islower(c))
            {
                c -= 32;
            }
            sentence = false;
        }
        else if (c == '.')
        {
            sentence = true;
        }
        os.put(c);
    }
}

// interleave the lines. Can assume lines are no longer
// than 1000 chars.
// take in strings
void interleave(string in1, string in2, string out)
{
    ifstream f1, f2;
    ofstream os;
    f1.open(in1);
    f2.open(in2);
    os.open(out);
    string line;
    do
    {
        if (getline(f1, line))
        {
            os << line << endl;
        }
        if (getline(f2, line))
        {
            os << line << endl;
        }
    } while (!f1.eof() || !f2.eof());
    f1.close();
    f2.close();
    os.close();
}

// Copy file. Straight-forward byte-to-byte copy
// Discuss why this works for binary files too
void copy(istream &is, ostream &os)
{
    char c;
    while (is.get(c))
    {
        os << c;
    }
}

int main(void)
{
    ifstream fp("pop.txt");
    printf("Alpha: %d\n", count_alpha(fp));

    fp.clear();
    fp.seekg(0);
    printf("Words: %d\n", count_words(fp));

    fp.clear();
    fp.seekg(0);
    printf("Sentences: %d\n", count_sentences(fp));
    fp.close();

    ifstream ifs("wind.txt");
    ifstream ifs2("pop.txt");
    ofstream ofs("out.txt");
    // reverse(ifs, ofs);
    // to_upper(ifs, ofs);
    // to_title_case(ifs, ofs);
    // to_sentence_case(ifs, ofs);

    // interleave("wind.txt", "pop.txt", "out.txt");
    copy(ifs, ofs);

    return 0;
}