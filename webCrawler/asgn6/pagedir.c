#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "pagedir.h"

bool pagedir_init(const char *pageDirectory) {
	if (access(pageDirectory,F_OK) != 0) {
		return false;
	}
	char *filepath = malloc(sizeof(char) * strlen(pageDirectory) + sizeof(char) * strlen("/.crawler") + sizeof(char));
	strcpy(filepath,pageDirectory);
	strcat(filepath,"/.crawler");
	FILE *file = fopen(filepath,"w");
	fclose(file);
	free(filepath);
	return true;
}

void pagedir_save(const webpage_t *page, const char *pageDirectory, const int documentID) {
	if (documentID > 9999) {
		printf("ERROR: document ID out of bounds");
		exit(EXIT_FAILURE);
	}
	char *tempID = malloc(sizeof(char) * 5);
	sprintf(tempID,"%d",documentID);
	char *filepath = malloc(sizeof(char) * strlen(pageDirectory) + sizeof(char) * strlen("/") + sizeof(char) * 5);
	strcpy(filepath,pageDirectory);
	strcat(filepath,"/");
	strcat(filepath,tempID);
	FILE *file = fopen(filepath,"w");
	fprintf(file,"%s\n",page->url);
	fprintf(file,"%d\n",page->depth);
	fprintf(file,"%s",page->html);
	fclose(file);
	free(tempID);
	free(filepath);
}
