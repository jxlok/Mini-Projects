/*Assignment_1 written by Jason Lok, 20366363, 20/03/21.
 * A C program which takes a list of songs, sorts and creates a playlist using the songs with
 * restrictions of time, number of appearances of artists and consecutive songs from an artist.
 *
 * When running the code, changing the run configuration's working directory to $ProjectFileDir$
 * is required as the program will check the current directory for a file in the case that one is not
 * specified
 *
 * When running in the terminal, cd cmake-build-debug first then run Assignment_1 (file name)
 * OR in the run configuration insert the file name into the program arguments segment. Don't forget to
 * take it back out when testing other parts of the code*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"    //imports library.h

//initialise arrays to be used
char newArray[NUM_SONGS][NAMES]={"\0"};
char tmparray[NUM_SONGS][NAMES]={"\0"};
char shuffled_array[NUM_SONGS][NAMES]={"\0"};
char playlist[NUM_SONGS][NAMES]={"\0"};

//universal variables
const char delim[] = "***";
int SIZE=0;

int main(int argc, char* argv[])
{

    //initialise first array
    char arr[NUM_SONGS][NAMES]= {'\0'};

    /*gets the random seed to be used in random number generator using current time*/
    srand(time(NULL));

    /*read function which acquires data either from file or user input and puts
     it into array arr*/
    read(arr, argc, argv);

    /*artists_songs function call which puts the artists with each of their songs in a new
     array (newArray)*/
    artists_songs(arr);

    /*sort function call which insertion sorts the array newArray alphabetically*/
    sort(newArray);

    /*shuffle function call which used Fisher-Yates inside-out algorithm to shuffle newArray into a
     new shuffled_array*/
    shuffle(newArray, shuffled_array);

    /*selection function call which goes through the shuffled_array and adds songs in to a playlist
    with the conditions, the last song starts before 3600 seconds/60mins, one artist can only appear
    max three times in the playlist and an artist can't appear three times in a row.*/
    selection(shuffled_array);

    return 0;
}

