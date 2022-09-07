#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int count_alpha(FILE *fp)
{
    int count = 0, c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (('a' <= c && c <= 'z') ||
            ('A' <= c && c <= 'Z'))
            count++;
    }
    return count;
}


int count_words(FILE *fp)
{
    int count = 0;
    while (fscanf(fp, "%*s") != EOF)
    {
        count++;
    }
    return count;
}

// Assume no word is longer than 255 characters
int count_sentences(FILE *fp)
{
    int count = 0;
    char word[256]; // words < 256
    while (fscanf(fp, "%s", &word) != EOF)
    {
        if (word[strlen(word) - 1] == '.')
        {
            count++;
        }
    }
    return count;
}

// Captialize every lower case letter
void to_upper(FILE *in, FILE *out)
{
    int c;
    while ((c = fgetc(in)) != EOF)
    {
        if ('a' <= c && c <= 'z')
        {
            fputc(c - 32, out);
        }
        else
        {
            fputc(c, out);
        }
    }
}

// Captialize first letter of every word
// Idea is to use a flag to check if we are
// at the start of a word.
void to_title_case(FILE *in, FILE *out)
{
    int c;
    bool cap = true;
    while ((c = fgetc(in)) != EOF)
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
        fputc(c, out);
    }
}

// Captialise first letter of each sentence
// Use the same technique as title casing of
// using a flag to check start of sentence.
void to_sentence_case(FILE *in, FILE *out)
{
    int c;
    bool sentence = true;
    while ((c = fgetc(in)) != EOF)
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
        fputc(c, out);
    }
}


// Copy file. Straight-forward byte-to-byte copy
// Discuss why this works for binary files too
void copy(FILE *in, FILE *out)
{
    int c;
    while ((c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }
}

int main()
{
    FILE *fp;
    fp = fopen("pop.txt", "r");
    printf("Alpha: %d\n", count_alpha(fp));
    rewind(fp);
    printf("Words: %d\n", count_words(fp));
    rewind(fp);
    printf("Sentences: %d\n", count_sentences(fp));
    fclose(fp);


    FILE *in = fopen("pop.txt", "r");
    FILE *in2 = fopen("wind.txt", "r");
    fp = fopen("tmp.txt", "w");
    to_sentence_case(in, fp);
    fclose(fp);
    fclose(in);
    fclose(in2);

    return 0;

}