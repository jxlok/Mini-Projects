//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*prints playlist in correct format*/
void print_playlist(char playlist[][NAMES], int size){

    printf("\n__Randomised playlist__\n");

    //tokens and prints in format artist: 'song' (duration)
    for(size_t i=0;i<size;i++){

        token = strtok(playlist[i], delim);
        strcpy(artists, token);

        token = strtok(NULL, delim);
        strcpy(songs, token);

        token = strtok(NULL, delim);
        strcpy(duration, token);

        printf("%s: '%s' (%s)\n", artists, songs, duration);
    }
}