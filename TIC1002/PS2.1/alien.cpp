#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/***********************************************************
   Part A. Planet related functions
***********************************************************/

//You can consider using the following defines to improve
// readability of your code

#define PLANET_SIZE 20

#define ALIVE 'X' 
#define DEAD 'O'

//This function is provided for you to review file stream
//Use similar idea for the save_alien_planet() function

void init_alien_planet( const char filename[], char alienPlanet[][PLANET_SIZE])
{
    ifstream inf(filename);
    char temp;
    int i, j;

    //Ensure the file can be opened
    if (!inf.is_open()){
        cout << "Error in opening file!\n";
        return;
    }
    //Proceed to read the file content into char 2D array
    for (i = 0; i < PLANET_SIZE; i++){
        for (j = 0; j < PLANET_SIZE; j++){
            inf >> alienPlanet[i][j];
        }
    }
    inf.close();
}


void save_alien_planet(const char filename[], char matrix[][20])
{
    
}


void evolve_alien_planet(char alienPlanet[][20], int nGeneration)
{

}

/***********************************************************
   Main function
***********************************************************/

int main( )
{
	//Two points:
	//1. If you use the suggested defines above
	//    this can be written as "char myPlanet[PLANET_SIZE][PLANET_SIZE];
	//2. May want to think about easier ways to handle the
	//    boundaries....
	char myPlanet[20][20];

	/*****************
     *    Testing    *
	 *****************/
    init_alien_planet("planet_sample.txt", myPlanet);
	evolve_alien_planet( myPlanet, 3);

	//One example on how to use the save file
	save_alien_planet("myresult_gen_3.txt", myPlanet);

    return 0;
}

