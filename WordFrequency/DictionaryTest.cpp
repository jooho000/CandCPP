/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA8
* DictionaryTest.cpp
* Dictionary ADT test cases
***/ 
#include "Dictionary.h"
using namespace std;

int main() {

    Dictionary A = Dictionary();
    Dictionary B = Dictionary();

    A.setValue("one", 1);
    A.setValue("two", 2);
    A.setValue("three", 3);
    A.setValue("four", 4);
    A.setValue("five", 5);
    A.setValue("six", 6);
    A.setValue("seven", 7);
    A.setValue("eight", 8);
    A.setValue("nine", 9);
    A.setValue("ten", 10);
    A.setValue("eleven", 11);
    A.setValue("twelve", 12);
    
    cout << A << endl;
    A.clear();

    A.setValue("hello", 1);
    A.setValue("my", 2);
    A.setValue("name", 3);
    A.setValue("is", 4);
    A.setValue("jooho", 5);
    A.setValue("lee", 6);

    B.setValue("hello", 1);
    B.setValue("my", 2);
    B.setValue("name", 3);
    B.setValue("is", 4);
    B.setValue("jooho", 5);
    B.setValue("lee", 100);

    cout << "A tree:\n" << A << endl;
    cout << A.pre_string() << endl;
    cout << "B tree:\n" << B << endl;
    cout << B.pre_string() << endl;

    bool isEqual = A == B;
    cout << "A == B(should be 0): " << isEqual << endl;
    B.setValue("lee",6);
    cout << "new B tree:\n" << B << endl;
    isEqual = A == B;
    cout << "A == B(should be 1): " << isEqual << endl;

    B.setValue("zebra",1000);
    B.remove("lee");
    B.remove("my");
    cout << "new B tree:\n" << B << endl;
    B.begin();
    keyType myKey = B.currentKey();
    valType myVal = B.currentVal();
    cout << "begin key of B: " << myKey << endl;
    cout << "begin val of B: " << myVal << endl;
    B.end();
    myKey = B.currentKey();
    myVal = B.currentVal();
    cout << "begin key of B: " << myKey << endl;
    cout << "begin val of B: " << myVal << endl;
    cout << "number of pairs for B: " << B.size() << endl;

    cout << "A tree:\n" << A << endl;
    cout << "B tree:\n" << B << endl;

    B = A;
    cout << "new B: \n" << B << endl;
    A.clear();
    if (A.contains("d"))
      cout << "failed test 1" << endl;

    A.setValue("d", 1);
    if (!A.contains("d"))
      cout << "failed test 2" << endl;

    A.remove("d");
    if (A.contains("d"))
      cout << "failed test 3" << endl;
    

    return EXIT_SUCCESS;
}