#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(char **argv) {

    float cels = atol(argv[1]);
    float faren = cels * 9 / 5 + 32;

    return 0;
}