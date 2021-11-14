//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*shuffle function which used Fisher-Yates inside-out algorithm to shuffle newArray into a
     new shuffled_array*/
void shuffle(char arr[][NAMES], char shuffled_array[][NAMES]){
    int j;

    //copies the original array into new array/to be shuffled array
    for(size_t i=0;i<SIZE;i++){
        strcpy(shuffled_array[i], arr[i]);
    }

    //Fisher-Yates inside-out algorithm
    for (size_t i = 1;  i < SIZE;  i++)
    {
        //sets j to random index
        j = rand() % i;

        //condition that it is a different index
        if(j!=i){
            //swaps positions pt.1
            strcpy(shuffled_array[i], shuffled_array[j]);
        }
        //swaps position pt.2
        strcpy(shuffled_array[j], arr[i]);
    }

}