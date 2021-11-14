//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*selection function which goes through the shuffled_array and adds songs in to a playlist
    with the conditions, the last song starts before 3600 seconds/60mins, one artist can only appear
    max three times in the playlist and an artist can't appear three times in a row.*/
void selection(char shuffled_array[][NAMES]){

    unsigned int playlist_time = 0;

    int song_time;
    int j=0;

    //copies shuffled_array into temporary array
    for(size_t i=0;i<SIZE;i++){
        strcpy(tmparray[i], shuffled_array[i]);
    }

    //adds songs into playlist array until playlist time exceeds 60mins
    for(size_t i=0;i<SIZE && playlist_time<3600;i++){

        //ignores empty lines
        if(strcmp(tmparray[i], "")==0){
            continue;
        }

        //tokens and stores the current lines artist, song and duration
        token = strtok(tmparray[i], delim);
        strcpy(artists, token);

        token = strtok(NULL, delim);
        strcpy(songs, token);

        token = strtok(NULL, delim);
        strcpy(duration, token);

        //checks if artist passes conditions and if yes puts it in the playlist
        if(check_artist(artists, playlist, j)==1){
            strcpy(playlist[j], shuffled_array[i]);

            //keeps track of playlist's duration as we go
            song_time = convert_to_sec(duration);
            playlist_time += song_time;

            j++;
        }


    }

    //prints playlist in specific format
    print_playlist(playlist, j);

    //prints duration of playlist
    print_in_minutes(playlist_time);

}