#include <iostream>
using namespace std;
 
const int MAXN = 14;              // biggest board (level 5)
const int MAXC = MAXN * MAXN;
 
int score = 0;
int lives = 3;
unsigned int seedv = 1;
char grid[MAXN][MAXN];            // '.' empty, 'X' wall, '$' food, '@' head, 'o' body
int n;
 
int myRand()                      // replaces rand()
{
    seedv = seedv * 1103515245u + 12345u;
    return (seedv >> 16) & 0x7fff;
}
