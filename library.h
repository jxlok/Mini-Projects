//
// Created by Jason Lok on 19/03/2021.
//

#ifndef ASSIGNMENT_1_LIBRARY_H
#define ASSIGNMENT_1_LIBRARY_H

//array max sizes defined
#define NAMES 80
#define DURATION 6
#define NUM_SONGS 60

//prototypes
void read(char arr[][NAMES], int argc, char* argv[]);
void sort(char arr[][NAMES]);
void artists_songs(char arr[][NAMES]);
void sort_print(char arr[][NAMES]);
void shuffle(char arr[][NAMES], char shuffled_array[][NAMES]);
void selection(char shuffled_array[][NAMES]);
int check_artist(char artist[NAMES], char playlist[][NAMES], int size);
int convert_to_sec(char arr[DURATION]);
void print_playlist(char playlist[][NAMES], int size);
void print_in_minutes(unsigned int time);

//initialising arrays globally
char newArray[NUM_SONGS][NAMES];
char tmparray[NUM_SONGS][NAMES];
char shuffled_array[NUM_SONGS][NAMES];
char playlist[NUM_SONGS][NAMES];

//global variables
const char delim[];
char artists[NAMES], songs[NAMES];
char duration[DURATION];

char *token;

int SIZE;

#endif //ASSIGNMENT_1_LIBRARY_H

