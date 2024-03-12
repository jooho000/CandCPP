/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA6
* Arithmetic.cpp
* BigInteger client
***/ 
#include "BigInteger.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    //checks number of arguements
    if (argc != 3) {
        printf("ERROR: wrong number of arguements for Arithmetic.cpp\n");
        exit(EXIT_FAILURE);
    }
    ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile) {
		cout << "Read file not created!";
	}

    ofstream outFile;
	outFile.open(argv[2]);
	if (!outFile) {
		cout << "Write file not created!";
	}

    string num1, num2;
    inFile >> num1;
    inFile >> num2;

    BigInteger A = BigInteger(num1);
    BigInteger B = BigInteger(num2);

    outFile << A << endl;
    outFile << endl;
    outFile << B << endl;
    outFile << endl;
    outFile << A + B << endl;
    outFile << endl;
    outFile << A - B << endl;
    outFile << endl;
    outFile << A - A << endl;
    outFile << endl;
    BigInteger temp = BigInteger(3);
    BigInteger temp2 = BigInteger(2);
    outFile << (A * temp) - (B * temp2) << endl;
    outFile << endl;
    outFile << A * B << endl;
    outFile << endl;
    outFile << A * A << endl;
    outFile << endl;
    outFile << B * B << endl;
    outFile << endl;
    BigInteger temp3 = BigInteger(9);
    BigInteger temp4 = BigInteger(16);
    outFile << (A*A*A*A*temp3) + (B*B*B*B*B*temp4) << endl;
    inFile.close();
    outFile.close();

    return EXIT_SUCCESS;
}