#include<iostream>
#include<sstream>
using namespace std;

string makeFinalString(string);

int main() {
    int myNumbers = 192745;
    string myString,finalString;
    stringstream ss;
    ss << myNumbers;
    ss >> myString;

    finalString = makeFinalString(myString);
    cout << finalString;
    return 0;
}

string makeFinalString(string myString) {
    const int size = myString.length();
    string finalString;
    for (size_t i = 0; i < size; i++)
    {
        if (myString[i] == '0') {
            finalString = finalString + "zero, ";
        } else if (myString[i] == '1') {
            finalString = finalString + "one, ";
        } else if (myString[i] == '2') {
            finalString = finalString + "two, ";
        } else if (myString[i] == '3') {
            finalString = finalString + "three, ";
        } else if (myString[i] == '4') {
            finalString = finalString + "four, ";
        } else if (myString[i] == '5') {
            finalString = finalString + "five, ";
        } else if (myString[i] == '6') {
            finalString = finalString + "six, ";
        } else if (myString[i] == '7') {
            finalString = finalString + "seven, ";
        } else if (myString[i] == '8') {
            finalString = finalString + "eight, ";
        } else if (myString[i] == '9') {
            finalString = finalString + "nine, ";
        } else {
            finalString = finalString + "unknown value, ";
        }
    }
    return finalString;
}