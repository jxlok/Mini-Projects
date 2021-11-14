//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

//function to print sorted array in a certain format
void sort_print(char arr[][NAMES]){

    char artists2[NAMES];

    //copies array into tmp array
    for(size_t i=0;i<SIZE;i++){
        strcpy(tmparray[i], arr[i]);
    }

    printf("\n__Sorted__");

    //tokens and prints sorted array out
    for (size_t i = 0; i < SIZE;i++) {

        //ignores empty lines
        if(strcmp(tmparray[i], "")==0){
            continue;
        }

        //gets artist from current line
        token = strtok(tmparray[i], delim);
        strcpy(artists2, token);

        //if the artist is the same as the previous line prints just the song and duration
        if(strcmp(artists2, artists)==0){

            token = strtok(NULL, delim);
            strcpy(songs, token);

            token = strtok(NULL, delim);
            strcpy(duration, token);

            printf("o %s***%s\n", songs, duration);
        }

            //otherwise prints the artist on one line and the songs and duration on the next
        else {
            //copies current artist (artist2) into artists for future comparison
            strcpy(artists, artists2);

            token = strtok(NULL, delim);
            strcpy(songs, token);

            token = strtok(NULL, delim);
            strcpy(duration, token);

            printf("\n%s\n", artists);
            printf("o %s***%s\n", songs, duration);
        }
    }
}