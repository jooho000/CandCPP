#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE 16

void printBinStatus(int, int);
int getIndex(int, int);

int main() {

    int myBins[ARRAY_SIZE], userInput, binSize = 1, binRange = 16;
    int *dynamicArray, dynamicSize = 1, count = 0;
    dynamicArray = (int*)malloc(dynamicSize * sizeof(int));
    printBinStatus(binSize,binRange);

    while (scanf("%d",&userInput) != EOF) {//loop for user input

        while (userInput > binRange) {//increases bin size if needed
            binRange = binRange * 2;
            binSize = binSize * 2;
            printBinStatus(binSize,binRange);
        }

        dynamicArray[dynamicSize-1] = userInput;
        dynamicSize++;
        dynamicArray = realloc(dynamicArray, dynamicSize * sizeof(int));//increases size of array

    }//end of loop for user input

    for (int i = 0; i < dynamicSize - 1; i++) {//loop in order know how many elements in the bin
        if (dynamicArray[i] >= 0) {
            myBins[getIndex(binSize,dynamicArray[i])] += 1;
        }
    }//end loop for finding elements in bin

    for (int j = 0; j < ARRAY_SIZE ;j++) {//prints the histogram 

        int width = 3;
        printf("[%*d:%*d] ",width, count, width, count + binSize - 1);
            for (int k = 0; k < myBins[j];k++) {
                printf("*");
            }
        count += binSize;
        printf("\n");
    }//end loop for printing histogram

    return 0;
}

//prints the message for bin size and range
void printBinStatus(int size, int range) {
    printf("16 bins of size %d for range [0,%d)\n",size,range);
}

//return index to where the number falls into the bin
int getIndex(int size, int target) {
    int result = target / size;
    return result;
}
