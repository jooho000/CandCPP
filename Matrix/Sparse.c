/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA4
* Sparce.c
* client for Matrix
***/ 
#include "Matrix.h"

int main(int argc, char** argv) {

    //checks number of arguements
    if (argc != 3) {
        printf("ERROR: wrong number of arguements for Sparce.c\n");
        exit(EXIT_FAILURE);
    }

    //opens files for reading and writing
    char* inFileString = argv[1];
    char* outFileString = argv[2];
    FILE *inFile = fopen(inFileString, "r");
    FILE *outFile = fopen(outFileString, "w");
    if (inFile == NULL) {
        printf("ERROR: inFile does not exit //Sparce.c\n");
        exit(EXIT_FAILURE);
    }
    if (outFile == NULL) {
        printf("ERROR: outFile does not exit //Sparce.c\n");
        exit(EXIT_FAILURE);
    }

    int clientSize, NNZA, NNZB, tempRow, tempCol;
    double tempVal;

    fscanf(inFile,"%d",&clientSize);
    fscanf(inFile,"%d",&NNZA);
    fscanf(inFile,"%d",&NNZB);

    //construct client matrices
    Matrix clientMatrixA = newMatrix(clientSize);
    Matrix clientMatrixB = newMatrix(clientSize);

    for (int i = 0 ; i < NNZA; i++) {
        fscanf(inFile, "%d", &tempRow);
        fscanf(inFile, "%d", &tempCol);
        fscanf(inFile, "%lf", &tempVal);
        changeEntry(clientMatrixA, tempRow, tempCol, tempVal);
    }

    for (int i = 0 ; i < NNZB; i++) {
        fscanf(inFile, "%d", &tempRow);
        fscanf(inFile, "%d", &tempCol);
        fscanf(inFile, "%lf", &tempVal);
        changeEntry(clientMatrixB, tempRow, tempCol, tempVal);
    }

    //print client matrices A and B
    fprintf(outFile, "A has %d non-zero entries:\n", NNZ(clientMatrixA));
    printMatrix(outFile, clientMatrixA);
    fprintf(outFile, "\n");
    fprintf(outFile, "B has %d non-zero entries:\n", NNZ(clientMatrixB));
    printMatrix(outFile, clientMatrixB);
    fprintf(outFile, "\n");

    //print scalar Matix (1.5) * A
    Matrix scalarMatrix = scalarMult(1.5, clientMatrixA);
    fprintf(outFile, "(1.5)*A =\n");
    printMatrix(outFile, scalarMatrix);
    fprintf(outFile, "\n");

    //print sum A + B and A + A
    Matrix sumAB = sum(clientMatrixA,clientMatrixB);
    Matrix sumAA = sum(clientMatrixA,clientMatrixA);
    fprintf(outFile, "A+B =\n");
    printMatrix(outFile, sumAB);
    fprintf(outFile, "\n");
    fprintf(outFile, "A+A =\n");
    printMatrix(outFile, sumAA);
    fprintf(outFile, "\n");

    //print B-A and A-A
    Matrix diffBA = diff(clientMatrixB, clientMatrixA);
    Matrix diffAA = diff(clientMatrixA, clientMatrixA);
    fprintf(outFile, "B-A =\n");
    printMatrix(outFile, diffBA);
    fprintf(outFile, "\n");
    fprintf(outFile, "A-A =\n");
    printMatrix(outFile, diffAA);
    fprintf(outFile, "\n");

    //print Transpose A
    Matrix transA = transpose(clientMatrixA);
    fprintf(outFile, "Transpose(A) =\n");
    printMatrix(outFile, transA);
    fprintf(outFile, "\n");

    //print A*B and B*B
    Matrix productAB = product(clientMatrixA, clientMatrixB);
    Matrix productBB = product(clientMatrixB, clientMatrixB);
    fprintf(outFile, "A*B =\n");
    printMatrix(outFile, productAB);
    fprintf(outFile, "\n");
    fprintf(outFile, "B*B =\n");
    printMatrix(outFile, productBB);
    fprintf(outFile, "\n");

    //free allocated matrices and close files
    freeMatrix(&clientMatrixA);
    freeMatrix(&clientMatrixB);
    freeMatrix(&scalarMatrix);
    freeMatrix(&sumAB);
    freeMatrix(&sumAA);
    freeMatrix(&diffBA);
    freeMatrix(&diffAA);
    freeMatrix(&transA);
    freeMatrix(&productAB);
    freeMatrix(&productBB);
    fclose(inFile);
    fclose(outFile);
    
    return EXIT_SUCCESS;
}