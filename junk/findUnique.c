#include<stdio.h>

int findCount(int[22], int);
void printUniques(int[22]);

int main() {

    int myArray[22] = {1,1,120,2,2,2,3,3,3,4,4,4,5,5,5,6,9,6,7,8,8,8,};
    printUniques(myArray);

    return 0;
}

int findCount(int myArray[22], int target) {
    
    int count = 0;
    for (int i = 0; i < 22 ; i++) {
        if (myArray[i] == target) {
            count++;
        }
    }

    return count;
}

void printUniques(int myArray[22]) {

    for (int i = 0; i < 22; i++) {
        if (findCount(myArray,myArray[i]) == 1) {
            printf("%d, ", myArray[i]);
        }
    }
    
}