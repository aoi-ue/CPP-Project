#include <iostream>

using namespace std;

#include <iostream> //for cout
#include <cstdio>   //you can use printf if needed

using namespace std;

void print_solid_slanted_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "#";
        }
        cout << endl;
    }
}

void print_solid_symmetric_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 1; k < height - i; k++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << "#";
        }

        for (int j = i; j > 0; j--)
        {
            cout << "#";
        }

        cout << endl;
    }
}

void print_hollow_symmetric_pyramid(
    int height, char outer, char inner)
{
    // rows
    for (int i = 1; i <= height; i++)
    {
        // spaces
        for (int s = i; s < height; s++)
        {
            cout << " ";
        }

        // hollow
        for (int h = 1; h <= (2 * i - 1); h++)
        {
            if (i == height || h == 1 || h == (2 * i - 1))
            {
                cout << outer; 
            }
            else
            {
                cout << inner; 
            }
        }

        cout << endl;
    }
}

int main(void)
{
    // print_solid_slanted_pyramid(4);
    // print_solid_symmetric_pyramid(4);
    print_hollow_symmetric_pyramid(4, '#', '$');
}
