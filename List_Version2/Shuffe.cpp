/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA5
* List.h
* header file for List.cpp
***/ 
#include "List.h"
#include<iomanip>
using namespace std;

void shuffle(List& D) {
    if (D.length() == 1 || D.length() == 0) {
        return;
    }
    D.moveFront();
    List temp;
    //cout << "intinital D: " << D << endl;
    int myNum = D.length()/2;
    for (int i = 0; i < myNum; i++) {
        temp.insertAfter(D.peekNext());
        temp.moveNext();
        D.eraseAfter();
    }
    //cout << "D: " << D << endl;
    //cout << "temp: " << temp << endl;
    D.moveFront();
    temp.moveFront();
    for (int i = 0; i < temp.length(); i++) {
        D.moveNext();
        D.insertAfter(temp.peekNext());
        temp.moveNext();
        D.moveNext();
    }
    temp.clear();
    //cout << "shuffled D: " << D << endl;

    return;
}

int main(int argc, char** argv) {

    //checks number of arguements
    if (argc != 2) {
        printf("ERROR: wrong number of arguements for Sparce.c\n");
        exit(EXIT_FAILURE);
    }

    int clientNum = atoi(argv[1]);
    List clientList;

    cout << "deck size       shuffle count" << endl;
    cout << "------------------------------";
    
    for (int i = 1; i < clientNum+1; i++) {
        clientList.insertAfter(i);
        clientList.moveNext();
        int count = 0;
        List temp = clientList;
        while (true) {
            shuffle(temp);
            count++;
            if (temp == clientList) {
                break;
            }
        }
        string myString = to_string(i);

        cout << "\n" << " " << i << setw(16) << count;
    }
    
}