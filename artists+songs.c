//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*function artists_songs which combines artists with their songs and puts it in a new array newArray*/
void artists_songs(char arr[][NAMES]){

    int i, j;

    /*takes line with songs***duration from initial array and appends into new array
      with artist***songs***duration*/
    for (i = 0; strcmp(arr[i], "")&&(i < SIZE); i++) {

        unsigned int length = strlen(arr[i]);

        //loop starts after an artist is found and continues until there is an empty line
        for (j = i+1; strcmp(arr[j], "")&&(j < SIZE); j++) {

            //copies the artist in
            strcpy(newArray[j], arr[i]);

            //copies *** after the artist on the same line
            strcpy(&newArray[j][length], "***");

            //copies the song***duration after artist***
            strcpy(&newArray[j][length+3], arr[j]);

        }

        //sets i to j to go to the next artist
        i=j;

    }
}