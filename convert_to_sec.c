//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*function to convert a string time to int seconds*/
int convert_to_sec(char arr[DURATION]){

    const char delimtime[] = ":";

    int minutes, seconds, total_seconds;

    //tokens using : as delim to acquire int minutes (atoi)
    token = strtok(arr, delimtime);
    minutes = atoi(token);

    //acquires int seconds using atoi
    token = strtok(NULL, delimtime);
    seconds = atoi(token);

    //converts minutes and seconds to just seconds
    total_seconds = (60*minutes) +seconds;

    //returns total seconds of songs
    return(total_seconds);
}