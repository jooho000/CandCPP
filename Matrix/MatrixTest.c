/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA4
* MatrixTest.h
* Test cases for Matrix ADT
***/ 
#include "Matrix.h"

int main() {
    FILE *outFile = fopen("myTestOut.txt", "w");
    Matrix A = newMatrix(10);
    Matrix B = newMatrix(10);

    changeEntry(A,1,1,1.0);
    changeEntry(A,1,2,2.0);
    changeEntry(A,1,3,3.0);
    changeEntry(A,2,1,4.0);
    changeEntry(A,2,2,5.0);
    changeEntry(A,2,3,6.0);
    changeEntry(A,3,1,7.0);
    changeEntry(A,3,2,8.0);
    changeEntry(A,3,3,9.0);

    changeEntry(B,1,1,1.0);
    changeEntry(B,1,3,1.0);
    changeEntry(B,3,1,1.0);
    changeEntry(B,3,2,1.0);
    changeEntry(B,3,3,1.0);

    fprintf(outFile,"Matrix A with %d NNZ:\n",NNZ(A));
    printMatrix(outFile,A);
    fprintf(outFile,"\n");
    fprintf(outFile,"Matrix B with %d NNZ:\n",NNZ(B));
    printMatrix(outFile,B);
    fprintf(outFile,"\n");

    Matrix copyA = copy(A);
    Matrix copyB = copy(B);

    fprintf(outFile,"Matrix copy of A with %d NNZ:\n",NNZ(copyA));
    printMatrix(outFile,copyA);
    fprintf(outFile,"\n");
    fprintf(outFile,"Matrix copy of B with %d NNZ:\n",NNZ(copyB));
    printMatrix(outFile,copyB);
    fprintf(outFile,"\n");


    Matrix scalarA = scalarMult(1.5,A);
    Matrix scalarB = scalarMult(2,B);

    fprintf(outFile,"A * 1.5 with %d NNZ:\n",NNZ(scalarA));
    printMatrix(outFile,scalarA);
    fprintf(outFile,"\n");
    fprintf(outFile,"B * 2 with %d NNZ:\n",NNZ(scalarB));
    printMatrix(outFile,scalarB);
    fprintf(outFile,"\n");

    Matrix transA = transpose(A);
    Matrix transB = transpose(B);

    fprintf(outFile,"A Transpose with %d NNZ:\n",NNZ(transA));
    printMatrix(outFile,transA);
    fprintf(outFile,"\n");
    fprintf(outFile,"B Transpose with %d NNZ:\n",NNZ(transB));
    printMatrix(outFile,transB);
    fprintf(outFile,"\n");

    Matrix productAB = product(A,B);
    Matrix productBB = product(B,B);

    fprintf(outFile,"A * B with %d NNZ:\n",NNZ(productAB));
    printMatrix(outFile,productAB);
    fprintf(outFile,"\n");
    fprintf(outFile,"B * B with %d NNZ:\n",NNZ(productBB));
    printMatrix(outFile,productBB);
    fprintf(outFile,"\n");


    Matrix sumABMatrix = sum(A,B);
    Matrix sumAAMatrix = sum(A,A);
    Matrix sumBBMatrix = sum(B,B);
    fprintf(outFile,"A + B with %d NNZ:\n",NNZ(sumABMatrix));
    printMatrix(outFile,sumABMatrix);
    fprintf(outFile,"\n");
    fprintf(outFile,"A + A with %d NNZ:\n",NNZ(sumAAMatrix));
    printMatrix(outFile,sumAAMatrix);
    fprintf(outFile,"\n");
    fprintf(outFile,"B + B with %d NNZ:\n",NNZ(sumBBMatrix));
    printMatrix(outFile,sumBBMatrix);
    fprintf(outFile,"\n");

    Matrix diffAA = diff(A,A);
    Matrix diffBB = diff(B,B);
    Matrix diffAB = diff(A,B);
    Matrix diffBA = diff(B,A);

    fprintf(outFile,"A - B with %d NNZ:\n",NNZ(diffAB));
    printMatrix(outFile,diffAB);
    fprintf(outFile,"\n");
    fprintf(outFile,"A - A with %d NNZ:\n",NNZ(diffAA));
    printMatrix(outFile,diffAA);
    fprintf(outFile,"\n");
    fprintf(outFile,"B - B with %d NNZ:\n",NNZ(diffBB));
    printMatrix(outFile,diffBB);
    fprintf(outFile,"\n");
    fprintf(outFile,"B - A with %d NNZ:\n",NNZ(diffBA));
    printMatrix(outFile,diffBA);
    fprintf(outFile,"\n");

    makeZero(A);
    makeZero(B);
    Matrix C = newMatrix(15);
    changeEntry(A, 1, 1, 1);
    changeEntry(C, 1, 1, 1);
    if (equals(A, C))
      fprintf(outFile, "fail test 1\n");
    Matrix D = newMatrix(15);
    changeEntry(A, 1, 1, 1);
    changeEntry(A, 1, 3, 1);
    changeEntry(B, 1, 1, 1);
    changeEntry(B, 1, 3, 1);
    if (!equals(A, B))
      fprintf(outFile, "fail test 2\n");
    changeEntry(A, 1, 3, 0);
    if (equals(A, B))
      fprintf(outFile, "fail test 3\n");
    changeEntry(A, 1, 1, 0);
    makeZero(B);
    changeEntry(A, 10, 10, 10);
    changeEntry(B, 10, 10, 10);
    if (!equals(A, B))
      fprintf(outFile, "fail test 4\n");

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    freeMatrix(&scalarA);
    freeMatrix(&scalarB);
    freeMatrix(&transA);
    freeMatrix(&transB);
    freeMatrix(&productAB);
    freeMatrix(&productBB);
    freeMatrix(&sumAAMatrix);
    freeMatrix(&sumABMatrix);
    freeMatrix(&sumBBMatrix);
    freeMatrix(&diffAA);
    freeMatrix(&diffAB);
    freeMatrix(&diffBB);
    freeMatrix(&diffBA);
    fclose(outFile);

    return 0;
}