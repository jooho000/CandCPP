#include<stdio.h>
#include<stdbool.h>

bool canJump(int*, int);

int main() {

    int myArray[5] = {3,2,1,0,4};
    const int length = sizeof(myArray) / sizeof(myArray[0]);

    if (canJump(myArray,length) == true) {
        printf("true");
    } else {
        printf("false");
    }
    
    return 0;
}

bool canJump(int* myArray, int length) {

    int myIndex = 0;
    myIndex = myIndex + myArray[0];

    while (myIndex <= length-1) {
        if (myIndex = length-1) {
            return true;
        } else if (myArray[myIndex] ==  0 && myIndex != length-1) {
            return false;
        } else {
            myIndex = myIndex + myArray[myIndex];
        }
    }

    return false;
}