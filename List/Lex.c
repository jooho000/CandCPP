#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include "List.h"

#define MAX_LEN 300

int main(int argc, char* argv[]) {
    int lengthOfClientArray = 0;
    char line[MAX_LEN];
    FILE *in, *inForCount, *out;

    //check for number of arguements
    if (argc != 3){
		printf("Error: incorrect number of arguements in Lex.c \n");
		exit(EXIT_FAILURE);
	}

    //opening files to work with also checks if opened succesfully
    in = fopen(argv[1], "r");
    inForCount = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	if (in == NULL) {
		printf("Error: Unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
    if (inForCount == NULL) {
		printf("Error: Unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (out == NULL) {
		printf("Error: Unable to open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

    //gets number of lines of the file and creates an array with size of number of lines
    while (fgets(line, MAX_LEN, inForCount) != NULL)  {
   		lengthOfClientArray++;
   	}
    char **clientArray = malloc(sizeof(char) * lengthOfClientArray * MAX_LEN);

    //inserts lines into array
    int countForArray;
    for (countForArray = 0; countForArray < lengthOfClientArray; countForArray++) {
        fgets(line, MAX_LEN, in);
        //printf("%s",line); //test
        char *tempString = malloc(sizeof(char*) * strlen(line));
        strcpy(tempString,line);
        //printf("%s",tempString); //test
        clientArray[countForArray] = tempString;
    }

    //for (int i = 0; i < lengthOfClientArray; i++) { printf("%s",clientArray[i]);} //test

    //create List and starts inserting in correct order
    List clientList = newList();
    int listCount;
    append(clientList, 0);
    for (listCount = 1; listCount < lengthOfClientArray; listCount++) {
        moveFront(clientList);
        while (index(clientList) != -1 && strcmp(clientArray[listCount],clientArray[get(clientList)]) < 0) {
            moveNext(clientList);
        }
        if (index(clientList) == -1) {
            append(clientList, listCount);
        } else {
            insertBefore(clientList,listCount);
        }
    }

    //prints into out file the array in sorted order
    moveBack(clientList);
    int printCount;
    for (printCount = 0; printCount < lengthOfClientArray; printCount++) {
   		fprintf(out, "%s", clientArray[get(clientList)]);
   		movePrev(clientList);
   	}

    //free heap memory
    int freeCount;
    for (freeCount = 0; freeCount < lengthOfClientArray; freeCount++) {
        free(clientArray[freeCount]);
    }
    free(clientArray);
    freeList(&clientList);

    //close files
    fclose(in);
    fclose(inForCount);
    fclose(out);
    
    return EXIT_SUCCESS;
}

