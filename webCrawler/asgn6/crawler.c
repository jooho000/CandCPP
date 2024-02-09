#include "crawler.h"
#include "pagedir.h"
#include "set.h"
#include "hashtable.h"
#include "url.h"
#include "curl.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


/**
 * Parses command-line arguments, placing the corresponding values into the pointer arguments seedURL,
 * pageDirectory and maxDepth. argc and argv should be passed in from the main function.
 */
static void parseArgs(const int argc, char *argv[], char **seedURL, char **pageDirectory, int *maxDepth) {
	if (seedURL == NULL || pageDirectory == NULL || maxDepth == NULL) {
		printf("ERROR: parameter not initialized");
		exit(EXIT_FAILURE);
	}
	if (argc != 4) {
		free(seedURL);
		free(pageDirectory);
		free(maxDepth);
		printf("ERROR: wrong number of arguements");
		exit(EXIT_FAILURE);
	}
	*maxDepth = atoi(argv[3]);
	if (*maxDepth > 10) {
		printf("ERROR: invalid max depth");
		exit(EXIT_FAILURE);
	}
	*seedURL = normalizeURL(argv[1],argv[1]);
	if (!pagedir_init(argv[2])) {
		printf("ERROR: directory does not exist");
		exit(EXIT_FAILURE);
	} else {
		*pageDirectory = malloc(sizeof(char) * strlen(*pageDirectory) + sizeof(char));
		strcpy(*pageDirectory,argv[2]);
	}
	//printf("%s   %s    %d",*seedURL,*pageDirectory,*maxDepth);
}


/**
 * Scans a webpage for URLs.
 */
static void pageScan(webpage_t *page, set_t *pagesToCrawl, hashtable_t *pagesSeen) {
	if (page == NULL || pagesToCrawl == NULL || pagesSeen == NULL) {
		printf("ERROR: pagescan has null parameters");
		exit(EXIT_FAILURE);
	}
	char *html = page->html;
	int index = 0;
	while (html[index + 1] != '\0') {
		if (strncmp(html + index, "<a href=\"",9) == 0) {
			char *tempString = malloc(sizeof(char));
			tempString[0] = '\0';
			int tempstringLength = 1;
			index += 9;
			while (html[index] != '"') {
				tempstringLength++;
				tempString = realloc(tempString, sizeof(char)*tempstringLength);
				tempString[tempstringLength-2] = html[index];
				tempString[tempstringLength-1] = '\0';
				index++;
			}
			char *oldTempString = tempString;
			tempString = normalizeURL(page->url,tempString);
			if (tempString == NULL) {
				free(oldTempString);
				continue;
			}
			if (isInternalURL(page->url,tempString)) {
				if (hashtable_insert(pagesSeen,tempString,page)){
					webpage_t *tempWebPage = malloc(sizeof(webpage_t));
					if (tempWebPage == NULL) {
						printf("ERROR: unable to initilize tempwebpage in page scanner");
						exit(EXIT_FAILURE);
					}
					tempWebPage->depth = page->depth+1;
					tempWebPage->url = tempString;
					tempWebPage->length = 0;
					tempWebPage->html = NULL;
					if (!set_insert(pagesToCrawl,tempString,tempWebPage)) {
						printf("ERROR: was not able to insert string in page scanner");
						exit(EXIT_FAILURE);
					}
				} else {
					//printf("%d	IGNDupl: %s\n",page->depth+1,tempString);
				}
			} else {
				//printf("%d	IGNExtern: %s\n",page->depth+1, tempString);
			}
			free(oldTempString);
		}
		index++;
	}
}

/**
 * Crawls webpages given a seed URL, a page directory and a max depth.
 */
static void crawl(char *seedURL, char *pageDirectory, const int maxDepth) {
	int docID = 1;
	hashtable_t *ht = hashtable_new(50);
	if (ht == NULL) {
		printf("ERROR: hashtable returned NULL");
		exit(EXIT_FAILURE);
	}
	webpage_t *newPage = malloc(sizeof(webpage_t));
	if (newPage == NULL) {
		printf("ERROR: unable to allocate memory for newPage");
		exit(EXIT_FAILURE);
	}
	newPage->url = seedURL;
	newPage->depth = 0;
	newPage->html = NULL;
	newPage->length = 0;
	if (!hashtable_insert(ht,seedURL,newPage)) {
		printf("ERROR: hashtable insert failure");
		exit(EXIT_FAILURE);
	}
	set_t *bag = set_new();
	if (bag == NULL) {
		printf("ERROR: failure on bag initialize");
		exit(EXIT_FAILURE);
	}

	if (!set_insert(bag,seedURL,newPage)) {
		printf("ERROR: not able to insert newPage to bag");
		exit(EXIT_FAILURE);
	}
	while (bag->firstElement != NULL) {
		webpage_t *page = fetchNode(bag)->item;
		printf("%s\n",page->url);
		printf("%d Fetched %s\n",page->depth,page->url);
		char *html = download(page->url,&(page->length));
		sleep(0.25);
		page->html = html;
		if (html == NULL) {
			printf("ERROR: html in download returned NULL");
			exit(EXIT_FAILURE);
		} else {
			pagedir_save(page,pageDirectory,docID);
			docID++;
			if (page->depth < maxDepth) {
				printf("%d	Scanning %s\n",page->depth, page->url);
				pageScan(page, bag, ht);
			}
		}
	}
	free(newPage);
	hashtable_delete(ht);
	set_delete(bag);
}

int main(const int argc, char *argv[]) {
	int maxDepth = 0;
	char *seedURL = malloc(sizeof(char));
	if (seedURL==NULL) {
		printf("ERROR: unable to initialize seed url");
		exit(EXIT_FAILURE);
	}
	char *pageDirectory = "";
	parseArgs(argc,argv,&seedURL,&pageDirectory,&maxDepth);
	crawl(seedURL,pageDirectory,maxDepth);
	free(seedURL);
	free(pageDirectory);
	return 0;
}
