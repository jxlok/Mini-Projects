//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*function to run checks for eligibility of being put into playlist*/
int check_artist(char artist[NAMES], char playlist[][NAMES], int size){

    char artistsInPlaylist[NAMES], last_artists[NAMES], last_artists2[NAMES];

    //copies playlist into tmp array
    for(size_t i=0;i<size;i++){
        strcpy(tmparray[i], playlist[i]);
    }

    //artist counter
    unsigned int artist_count = 0;

    //checks
    for(size_t i=0;i<size;i++){

        //checks last two in playlist and compares to selected song's artist to be added
        if(size>1 && (i==size-2)){
            token = strtok(tmparray[i], delim);
            strcpy(last_artists, token);

            token = strtok(tmparray[size-1], delim);
            strcpy(last_artists2, token);

            //if matched with both, doesn't add selected song due to triple play
            if((strcmp(artist, last_artists)==0)&&(strcmp(artist, last_artists2)==0)){
                return 2;
            }

            //if one matches increases counter, also breaks if counter reaches 3 (max 3 of one artist)
            if((strcmp(artist, last_artists)==0)||(strcmp(artist, last_artists2)==0)){
                artist_count += 1;
                if(artist_count == 3){
                    return 2;
                }
            }

            //passes
            return 1;

        }

        //tokens current artist in current line in playlist
        token = strtok(tmparray[i], delim);
        strcpy(artistsInPlaylist, token);

        //compares to selected song's artist and keeps count.
        //Breaks if count is already at 3
        if(strcmp(artistsInPlaylist, artist)==0){
            artist_count += 1;
            if(artist_count == 3){
                return 2;
            }
        }

    }

    //passes
    return 1;
}
