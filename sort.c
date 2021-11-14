//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

/*sort function which insertion sorts the array newArray alphabetically*/
void sort(char arr[][NAMES]){

    int j;
    char swap[NUM_SONGS][NAMES];
    char tmp[NUM_SONGS][NAMES];     //tmp array


    //insertion sort
    for (size_t i = 1; i < SIZE; i++) {

        j = i;
        strcpy(swap[i], arr[i]);

        //compares each line and checks if it is alphabetically correct
        while (j > 0 && strcmp(swap[i], arr[j - 1])<0)
        {
            strcpy(arr[j], arr[j-1]);
            j--;
        }
        strcpy(arr[j], swap[i]);

    }

    //prints sorted array in certain format
    sort_print(arr);

}