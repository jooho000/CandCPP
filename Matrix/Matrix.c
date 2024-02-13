/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA4
* Matrix.c
* Matrix ADT
***/ 
#include "Matrix.h"

typedef struct MatrixObj {
    int size;
    int NNZ;
    List *row;
} MatrixObj;

typedef struct inputNodeObj {
    int column;
    double value;
} inputNodeObj;

static inputNode newInput(int column, double value) {
    inputNode tempInput = (inputNode)malloc(sizeof(inputNodeObj));
    tempInput->column = column;
    tempInput->value = value;
    return tempInput;
}

static void freeInputNode(inputNode *pN){
    if (*pN == NULL || pN == NULL) {
        printf("ERROR: *pN or pN is NULL in freeInputNode() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    free(*pN);
    *pN = NULL;
}

Matrix newMatrix(int n) {
    Matrix tempMatrix = (Matrix)malloc(sizeof(MatrixObj));
    if (tempMatrix == NULL) {
        printf("ERROR: malloc for tempMatrix returned NULL in newMatrix() //Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    tempMatrix->size = n;
    tempMatrix->NNZ = 0;
    tempMatrix->row = (List*)malloc((n+1) * sizeof(List));
    if (tempMatrix->row == NULL) {
        printf("ERROR: malloc for temprow returned NULL in newMatrix() //Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < n+1; i++) {
        tempMatrix->row[i] = newList();
    }
    return tempMatrix;
}

void freeMatrix(Matrix* pM) {
    if (*pM != NULL && pM != NULL) {
        
        makeZero((*pM));
        for (int i = 1; i < size(*pM)+1; i++) {
            freeList(&(*pM)->row[i]);
        }
        free((*pM)->row);
        free(*pM);
        *pM = NULL;
    }
}

int size(Matrix M) {
    if (M == NULL) {
        printf("ERROR: M is null in size() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    return M->size;
}

int NNZ(Matrix M) {
    if (M == NULL) {
        printf("ERROR: M is null in NNZ() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    return M->NNZ;
}

int equals(Matrix A, Matrix B) {
    if (A == NULL) {
        printf("ERROR: A is null in equals() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    if (B == NULL) {
        printf("ERROR: B is null in equals() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    int isEqual = 0;
    if (size(A) != size(B)) {
        return isEqual;
    }
    for (int i = 1; i < size(A)+1; i++) {
        moveFront(A->row[i]);
        moveFront(B->row[i]);
        if (length(A->row[i]) != length(B->row[i])) {
            return isEqual;
        }
        while (index(A->row[i]) != -1 && index(B->row[i]) != -1) {
            inputNode curr = get(A->row[i]);
            inputNode curr2 = get(B->row[i]);
            if (curr->column != curr2->column || curr->value != curr2->value) {
                return isEqual;
            }
            moveNext(A->row[i]);
            moveNext(B->row[i]);
        }
    }
    isEqual = 1;
    return isEqual;
}

void makeZero(Matrix M) {
    if (M == NULL) {
        printf("ERROR: M is null in makeZero() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < size(M)+1; i++) {
        if (length(M->row[i]) != 0) {
            moveFront(M->row[i]);
            inputNode curr;
            while (index(M->row[i]) != -1) {
                curr = get(M->row[i]);
                freeInputNode(&curr);
                moveNext(M->row[i]);
            }
            clear(M->row[i]);
        }
    }
    M->NNZ = 0;
}

static bool isInRow(List L, int col) {
    if (length(L) ==0) {
        return false;
    }
    moveFront(L);
    inputNode curr;
    while (index(L) != -1) {
        curr = get(L);
        if (curr->column == col) {
            return true;
        }
        moveNext(L);
    }
    return false;
}

static void insertInput(List L, int j, double x) {
    if (length(L) == 0) {
        inputNode tempIn = newInput(j,x);
        append(L,tempIn);
        return;
    }
    inputNode curr;
    if (isInRow(L,j)) {
        curr = get(L);
        curr->value = x;
        return;
    }
    moveFront(L);
    while (index(L) != -1) {
        curr = get(L);
        if (curr->column < j) {
            moveNext(L);
        } else {
            inputNode tempIn = newInput(j,x);
            insertBefore(L,tempIn);
            return;
        }
    }
    inputNode tempIn = newInput(j,x);
    moveBack(L);
    insertAfter(L,tempIn);
    return;
}

void changeEntry(Matrix M, int i, int j, double x) {
    if (M == NULL) {
        printf("ERROR: M is null in changeEntry() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    List currList = M->row[i];
    inputNode curr;
    if (isInRow(currList,j)) {
        curr = get(currList);
        if (x == 0) {
            freeInputNode(&curr);
            delete(currList);
            M->NNZ--;
        } else {
            curr->value = x;
        }
    }
    if (x != 0) {
        insertInput(currList,j,x);
        M->NNZ++;
    }
}

Matrix copy(Matrix A) {
    if (A == NULL) {
        printf("ERROR: A is null in copy() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    Matrix copiedMatrix = newMatrix(size(A));
    copiedMatrix->NNZ = A->NNZ;
    inputNode curr;
    for (int i = 1; i < size(A) + 1; i++) {
        moveFront(A->row[i]);
        while (index(A->row[i]) != -1) {
            curr = get(A->row[i]);
            inputNode newInsert = newInput(curr->column,curr->value);
            append(copiedMatrix->row[i], newInsert);
            moveNext(A->row[i]);
        }
    }
    return copiedMatrix;
}

Matrix transpose(Matrix A) {
    if (A == NULL) {
        printf("ERROR: A is null in transpose() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    Matrix tempMatrix = newMatrix(size(A));
    tempMatrix->NNZ = A->NNZ;
    inputNode curr;
    for (int i = 1; i < size(A) + 1; i++) {
        if (length(A->row[i]) != 0) {
            moveFront(A->row[i]);
            while(index(A->row[i]) != -1) {
                curr = get(A->row[i]);
                inputNode newIn = newInput(i,curr->value);
                append(tempMatrix->row[curr->column],newIn);
                moveNext(A->row[i]);
            }
        }
    }
    return tempMatrix;
}

Matrix scalarMult(double x, Matrix A) {
    if (A == NULL) {
        printf("ERROR: A is null in scalarMult() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    Matrix temp = copy(A);
    inputNode curr;
    for (int i = 1; i < size(temp) + 1; i++) {
        moveFront(temp->row[i]);
        while (index(temp->row[i]) != -1) {
            curr = get(temp->row[i]);
            curr->value *= x;
            moveNext(temp->row[i]);
        }
    }
    return temp;
}

Matrix sum(Matrix A, Matrix B) {
    if (A == NULL) {
        printf("ERROR: A is null in sum() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    if (B == NULL) {
        printf("ERROR: B is null in sum() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    List currTempList,currListB;
    inputNode currTemp,currB;
    Matrix tempMatrix = copy(A);
    for (int i = 1; i < size(A) + 1; i++) {
        currTempList = tempMatrix->row[i];
        currListB = B->row[i];
        moveFront(currListB);
        while (index(currListB) != -1) {
            currB = get(currListB);
            if (isInRow(currTempList,currB->column)) {
                currTemp = get(currTempList);
                currTemp->value += currB->value;
                if (currTemp->value == 0) {
                    freeInputNode(&currTemp);
                    delete(currTempList);
                    tempMatrix->NNZ--;
                }
            } else {
                insertInput(currTempList,currB->column,currB->value);
                tempMatrix->NNZ++;
            }
            moveNext(currListB);
        }
    }

    return tempMatrix;
}

Matrix diff(Matrix A, Matrix B) {
    if (A == NULL) {
        printf("ERROR: A is null in diff() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    if (B == NULL) {
        printf("ERROR: B is null in diff() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    List currTempList,currListB;
    inputNode currTemp,currB;
    Matrix tempMatrix = copy(A);
    for (int i = 1; i < size(A) + 1; i++) {
        currTempList = tempMatrix->row[i];
        currListB = B->row[i];
        moveFront(currListB);
        while (index(currListB) != -1) {
            currB = get(currListB);
            if (isInRow(currTempList,currB->column)) {
                currTemp = get(currTempList);
                currTemp->value -= currB->value;
                if (currTemp->value == 0) {
                    freeInputNode(&currTemp);
                    delete(currTempList);
                    tempMatrix->NNZ--;
                }
            } else {
                insertInput(currTempList,currB->column,-currB->value);
                tempMatrix->NNZ++;
            }
            moveNext(currListB);
        }
    }

    return tempMatrix;
}

static double vectorDot(List P, List Q) {
    if (P == NULL) {
        printf("ERROR: P is null in vectorDot() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    if (Q == NULL) {
        printf("ERROR: Q is null in vectorDot() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    if (length(P) == 0 || length(Q) == 0) {
        return 0;
    }
    double result = 0;
    List longerList,shorterList;
    if (length(P) >= length(Q)) {
        longerList = P;
        shorterList = Q;
    } else {
        longerList = Q;
        shorterList = P;
    }

    inputNode currLong, currShort;
    moveFront(shorterList);
    while (index(shorterList) != -1) {
        currShort = get(shorterList);
        if (isInRow(longerList,currShort->column)) {
            moveFront(longerList);
            currLong = get(longerList);
            while (currShort->column != currLong->column) {
                moveNext(longerList);
                currLong = get(longerList);
            }
            result += (currShort->value * currLong->value);
        }
        moveNext(shorterList);
    }
    return result;
}

Matrix product(Matrix A, Matrix B) {
    if (A == NULL) {
        printf("ERROR: A is null in product() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    if (B == NULL) {
        printf("ERROR: B is null in product() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    Matrix transB = transpose(B);
    Matrix myProduct = newMatrix(size(A));
    myProduct->NNZ = 0;
    for (int i = 1; i < size(myProduct) +1; i++) {
        if (length(A->row[i]) != 0 || length(transB->row[i]) != 0) {
            for (int j = 1; j < size(myProduct) + 1; j++) {
                double dotProduct = vectorDot(A->row[i],transB->row[j]);
                if (dotProduct == 0) {

                } else {
                    insertInput(myProduct->row[i],j,dotProduct);
                    myProduct->NNZ++;
                }
            }
        }
    }
    freeMatrix(&transB);
    return myProduct;
}

void printMatrix(FILE* out, Matrix M) {
    if (out == NULL) {
        printf("ERROR: out is null in printMatrix() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    if (M == NULL) {
        printf("ERROR: M is null in printMatrix() // Matrix.c\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < size(M) + 1; i++) {
        List currList = M->row[i];
        inputNode curr;
        moveFront(currList);
        if (length(currList) != 0) {
            fprintf(out,"%d: ",i);
            while (index(currList) != -1) {
                curr = get(currList);
                fprintf(out,"(%d, %.1lf) ",curr->column,curr->value);
                moveNext(currList);
            }
            fprintf(out,"\n");
        }
    }
}