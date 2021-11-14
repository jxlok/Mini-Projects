//
// Created by Jason Lok on 19/03/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "library.h" //import library

/*read function which reads from a file or user input for song data and puts it in an array*/
void read(char arr[][NAMES], int argc, char* argv[])
{
    FILE *fp;

    if(argc>1) {

        //if user input filename cant be read or doesn't exist
        if ((fp = fopen(argv[1], "r")) == NULL) {
            printf("File does not exist or is not readable.\n");
            exit(1);
        }
            //if artistes+songs.txt can be found in directory
        else {
            //copies from file into array until the end of file
            for (size_t j = 0; j < NUM_SONGS && !feof(fp); j++) {

                fgets(arr[j], NAMES, fp);

                if (arr[j][strlen(arr[j]) - 1] == '\n')
                    arr[j][strlen(arr[j]) - 1] = '\0';

                //keeps track of file size
                SIZE += 1;

            }
        }
    }
        //no file supplied
    else {
        //Checks current directory for a file artistes+songs.txt
        printf("\nNo file specified. Checking current directory...\n");

        //if artistes+songs.txt can't be found
        if ((fp = fopen("artistes+songs.txt", "r")) == NULL) {
            printf("No file found.\n");

            //prompts user to manually input data and hit enter twice when done
            printf("\nEnter artistes and songs information in format:\n"
                   "Artiste name\n"
                   "Song title***Song duration\n"
                   "Song title***Song duration\n"
                   "...\n"
                   "Song title***Song duration\n"
                   "<blank line>\n"
                   "Artiste name\n"
                   "Song title***Song duration\n"
                   "Song title***Song duration\n"
                   "...\n"
                   "Song title***Song duration\n"
                   "<blank line>\n"
                   "...\n"
                   "(Hit enter twice to finish)\n\n");

            //takes user input from console
            for (size_t i = 0; i < NUM_SONGS; i++) {

                fgets(arr[i], NAMES, stdin);

                //breaks when user hits enter twice
                if ((strcmp(arr[i], "\n") == 0) && (strcmp(arr[i - 1], "") == 0)) {
                    break;
                }

                //strips newline from end of line
                if (arr[i][strlen(arr[i]) - 1] == '\n') {
                    arr[i][strlen(arr[i]) - 1] = '\0';
                }

                //keeps track of size of file
                SIZE += 1;

            }
        }

            //if artistes+songs.txt can be found in current directory
        else {
            //copies from filename file into array until end of file
            for (size_t j = 0; j < NUM_SONGS && !feof(fp); j++) {

                fgets(arr[j], NAMES, fp);

                if (arr[j][strlen(arr[j]) - 1] == '\n') {
                    arr[j][strlen(arr[j]) - 1] = '\0';

                    //keeps track of file size
                    SIZE += 1;
                }

            }
        }
    }
    //close file
    fclose(fp);

}