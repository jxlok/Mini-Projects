//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*converts and prints the playlist duration in minutes and seconds*/
void print_in_minutes(unsigned int time){

    int minutes, seconds;

    minutes = (time/60);
    seconds = time-(minutes*60);

    //in the case of single digit seconds adds a 0 prior to it
    if(seconds<10){
        printf("\nTotal duration: %d:0%d. ", minutes, seconds);
        return;
    }

    printf("\nTotal duration: %d:%d. ", minutes, seconds);
}