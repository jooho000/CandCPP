#include<stdio.h>
#include<string.h>
#include<math.h>

void doPower();
void doSum();
void doProduct();
void doDifference();
void doQuotient();

int main() {
    char userAnswer[50];
    printf("What would you like to do?\n");
    scanf("%s", &userAnswer);

    if (strcmp(userAnswer,"power") == 0) {
        doPower();
    } else if (strcmp(userAnswer,"sum") == 0) {
        doSum();
    } else if (strcmp(userAnswer,"product") == 0) {
        doProduct();
    } else if (strcmp(userAnswer,"difference") == 0) {
        doDifference();
    } else if (strcmp(userAnswer,"divide") == 0) {
        doQuotient();
    } else {
        printf("invalid statement");
    }
    
    return 0;
}


void doPower() {
    double powerNum, myNumber;
    printf("enter your number: \n");
    scanf("%lf", &myNumber);
    printf("to the power of?\n");
    scanf("%lf", &powerNum);
    double result = pow(myNumber,powerNum);
    printf("%.2lf to the power of %.2lf is: %.2lf\n",myNumber,powerNum,result);
}

void doSum() {
    double num1,num2;
    printf("enter number: \n");
    scanf("%lf",&num1);
    printf("plus\n");
    scanf("%lf",&num2);
    double result = num1 + num2;
    printf("the sum of %.2lf and %.2lf is %.2lf\n",num1,num2,result);
}

void doProduct() {
    double num1,num2;
    printf("enter frist number to multiply\n");
    scanf("%lf",&num1);
    printf("enter second number\n");
    scanf("%lf",&num2);
    printf("the result is %.2lf\n", num1*num2);
}

void doDifference() {
    double num1,num2;
    printf("enter frist number to subtract\n");
    scanf("%lf",&num1);
    printf("enter second number\n");
    scanf("%lf",&num2);
    printf("the difference is %.2lf\n", num1-num2);
}

void doQuotient() {
    double num1,num2;
    printf("enter frist number to divide\n");
    scanf("%lf",&num1);
    printf("enter second number\n");
    scanf("%lf",&num2);
    printf("the quotient is %.2lf\n", num1/num2);
}
