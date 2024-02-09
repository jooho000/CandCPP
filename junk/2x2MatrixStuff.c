#include<stdio.h>
#include<stdlib.h>

void setMatrix(int[5][5]);
void printMatrix(int[5][5]);
void printMatrixPresance(int[5][5], int);
int isInMatrix(int[5][5],int);


int main() {

    int myMatrix[5][5];
    setMatrix(myMatrix);
    printMatrix(myMatrix);
    printMatrixPresance(myMatrix,4);
    int matrix2[5][5];
    setMatrix(matrix2);


    return 0;
}

void setMatrix(int myMatrix[5][5]) {

    int rand();
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            myMatrix[i][j]= rand() %50;
        }
    }
}

void printMatrix(int myMatrix[5][5]) {

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            printf("%d, ",myMatrix[i][j]);
        }
        printf("\n");
    }
}

void printMatrixPresance(int myMatrix[5][5], int target) {
    
    if (isInMatrix(myMatrix,target) == 1) {
        printf("%d is in matrix\n",target);
    } else {
        printf("%d is not in matrix\n",target);
    }

}

int isInMatrix(int myMatrix[5][5], int target) {

    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            if (myMatrix[i][j]==target) {
                return 1;
            }
        }
    }

    return 0;
}

