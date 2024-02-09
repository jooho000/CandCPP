#include<stdio.h>

void printHello();
int myNumber();
int number3();

int main() {
    printf("hello");
    printHello();
    printf("%d",myNumber());
    printf("\nthis is hello number %d", number3());
    return 0;
}

void printHello() {
    printf("\nhello");
}

int myNumber() {
    return 2;
}

int number3() {
    return 3;
}