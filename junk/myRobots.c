#include<stdio.h>
#include<string.h>

#define NAME_SIZE 10

typedef struct myRobot {
    char name[NAME_SIZE];
    int damage;
    int hitPoint;
    int speed;
} myRobot;

myRobot setBot();

void battle(myRobot,myRobot);

int main() {
    myRobot robot1,robot2;
    robot1 = setBot();
    robot2 = setBot();

    return 0;
}

myRobot setBot() {
    myRobot tempBot;
    char tempName[NAME_SIZE];
    int tempNum;
    printf("enter bot name: ");
    scanf("%s",tempName);
    strncpy(tempBot.name, tempName, NAME_SIZE);
    printf("enter bot dmg: ");
    scanf("%d",&tempNum);
    tempBot.damage = tempNum;
    printf("enter bot HP: ");
    scanf("%d",&tempNum);
    tempBot.hitPoint = tempNum;
    printf("enter bot speed: ");
    scanf("%d",&tempNum);
    tempBot.speed = tempNum;

    return tempBot;
}

void battle(myRobot bot1, myRobot bot2) {
    int HP1 = bot1.hitPoint, HP2 = bot2.hitPoint;

    while (HP1 > 0 && HP2 > 0) {
        int turnCount = 1;

        
        
    }


}