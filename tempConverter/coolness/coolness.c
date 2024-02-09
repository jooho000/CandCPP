#include<stdio.h>
#include<stdlib.h>
#include<math.h>\

float getResult(float, float);
void doNoInputs();
void doOneInput(float);
void doTwoInputs(float,float);

int main(int argC, char **argV) {

    //checks number of inputs
    if (argC > 3) {
        printf("Usage: ./coolness [temperature] [wind speed]\n");
        return 1;
    } 

    if (argC == 1) { //if there are no inputs

        doNoInputs();

    } else if (argC == 2) { //if there is one input

        if (atof(argV[1]) < -99) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
            return 1;
        } else if (atof(argV[1]) > 50) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
            return 1;
        }
        doOneInput(atof(argV[1]));

    } else {//the only case left where there are 2 inputs

        if (atof(argV[1]) < -99) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
            return 1;
        } else if (atof(argV[1]) > 50) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
            return 1;
        } else if (atof(argV[2]) < 0.5) {
            printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
            return 1;
        }
        doTwoInputs(atof(argV[1]),atof(argV[2]));

    }

    return 0;
}//end main

//function to get the result from given formula with T and V
float getResult(float T, float V) {
    float result;
    float tempNum = pow(V,0.16);
    result = 35.74 +  (0.6215*T) - (35.75*tempNum) + (0.4275*T) * tempNum;

    return result;
}

//function to run when there were no inputs
void doNoInputs() {
    float T = -10;
    float V = 5;
    int i;

    printf("Temp\tWind\tCoolness\n");

    for (i = 0; i < 3; i++) {
        printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
        V += 5;
    }

    printf("\n");
    T += 10;
    V =5;

    for (i = 0; i < 3; i++) {
        printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
        V += 5;
    }

    printf("\n");
    T += 10;
    V =5;

    for (i = 0; i < 3; i++) {
        printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
        V += 5;
    }

    printf("\n");
    T += 10;
    V =5;

    for (i = 0; i < 3; i++) {
        printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
        V += 5;
    }

    printf("\n");
    T += 10;
    V =5;

    for (i = 0; i < 3; i++) {
        printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
        V += 5;
    }

    printf("\n");
    T += 10;
    V =5;

    for (i = 0; i < 3; i++) {
        printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
        V += 5;
    }
}

//function to run when there was one input
void doOneInput(float T) {
    float V = 5;

    printf("Temp\tWind\tCoolness\n");
    for (int i = 0; i < 3; i++) {
        printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
        V += 5;
    }
}

//function to run when there were 2 inputs
void doTwoInputs(float T, float V) {
    printf("Temp\tWind\tCoolness\n");
    printf("%.1f\t%.1f\t%.1f\n",T,V,getResult(T,V));
}