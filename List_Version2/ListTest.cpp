/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA5
* ListTest.cpp
* test cases for List ADT
***/ 
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

using namespace std;

int main() {
    List L;
    List A;

    A.insertAfter(77);
    A.insertAfter(55);
    A.insertAfter(1);
    A.insertAfter(34);
    A.insertAfter(1);
    A.insertAfter(77);
    A.insertAfter(77);
    A.insertAfter(34);
    cout <<"A before cleanup(): " << A << endl;
    cout << "A position(): " << A.position() << endl;
    A.moveFront();
    A.cleanup();
    cout << "A after cleanup(): " << A << endl;
    cout << "A position() after cleanup: " << A.position() << endl;
  
    L.moveFront();
    L.insertAfter(1);
    L.moveNext();
    L.insertAfter(2);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(4);
    L.moveNext();
    L.insertAfter(5);
    L.moveNext();
    L.insertAfter(6);
    L.insertBefore(9);
    L.insertBefore(9);
    L.eraseAfter();
    L.moveFront();
    L.eraseAfter();
    L.moveBack();
    L.movePrev();
    L.eraseAfter();
    L.insertBefore(100);
    L.moveFront();
    L.setAfter(50);
    L.moveBack();
    L.setBefore(30);
    L.moveBack();
    L.eraseBefore();
    L.moveFront();
    L.moveNext();
    L.eraseBefore();

    ListElement frontNum = L.front();
    ListElement backNum = L.back();

    cout << "L: " << L << endl;
    cout << "L front = " << frontNum << endl;
    cout << "L back = " << backNum << endl;
    cout << "L length = " << L.length() << endl;
    L.moveFront();
    cout <<"position of '4' is: " << L.findNext(4) << endl;
    L.moveFront();
    cout <<"position of '6' is: " << L.findNext(6) << endl;
    L.moveBack();
    cout <<"position of '4' is: " << L.findPrev(4) << endl;
    L.moveBack();
    cout <<"position of '6' is: " << L.findPrev(6) << endl;

    cout << L << endl;

    L.clear();
    cout << "length after clear = " << L.length() << endl;

    List L2;

    L.moveFront();
    L.insertAfter(1);
    L.moveNext();
    L.insertAfter(2);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(4);
    L.moveNext();

    L2.moveFront();
    L2.insertAfter(1);
    L2.moveNext();
    L2.insertAfter(2);
    L2.moveNext();
    L2.insertAfter(3);
    L2.moveNext();
    L2.insertAfter(4);
    L2.moveNext();

    cout << "L: " << L << endl;
    cout << "L2: " << L2 << endl;
    cout << "L == L2 (should be 1): " << (L == L2) << endl;

    L2.insertAfter(5);
    L2.moveNext();
    L2.insertAfter(6);
    L2.moveNext();
    cout << "L == L2 (should be 0): " << (L == L2) << endl;

    L2.clear();
    L2 = L;
    cout << "L == L2 (should be 1): " << (L == L2) << endl;
    
    cout << "L: " << L << endl;
    cout << "L2: " << L2 << endl;
    cout << "L2 front: " << L2.front() << endl;
    cout << "L2: back: " << L2.back() << endl;

    L.clear();
    cout << "L after clear(): " << L << endl;
    L.moveFront();
    L.insertAfter(1);
    L.moveNext();
    L.insertAfter(1);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(1);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(1);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(1);
    L.moveNext();
    L.insertAfter(3);
    L.moveNext();
    L.insertAfter(3);
    L.moveFront();
    cout <<"L: " << L << endl;
    cout << "position: " << L.position() << endl;;

    L.cleanup();
    cout << "L after cleanup(): " << L << endl;
    cout << "position: " << L.position() << endl;

    L.clear();

    L.insertAfter(33);
    L.insertAfter(33);
    L.insertAfter(33);
    L.insertAfter(33);
    L.insertAfter(34);
    L.insertAfter(34);
    L.insertAfter(34);
    L.insertAfter(366);
    L.insertAfter(388);
    L.insertAfter(32);
    L.insertAfter(33);

    cout << "L before cleanup(): " << L << endl;
    L.cleanup();
    cout << "L after cleanup(): " << L << endl;
    cout << "position: " << L.position() << endl;

    A.clear();

    A.insertBefore(5);
    A.insertBefore(10);
    A.insertBefore(15);
    A.insertBefore(176);
    A.insertBefore(200);
    A.findPrev(15);
    A.eraseBefore();
    if (A.position() != 1)
      cout << "failed test 1" << endl;

    A.insertAfter(175);
    A.eraseBefore();
    if (A.position() != 0)
      cout << "failed test 2" << endl;

    A.insertBefore(15);
    A.insertBefore(50);
    if (A.position() != 2)
      cout << "failed test 3" << endl;

    A.findNext(15);
    A.eraseBefore();
    if (A.position() != 3)
      cout << "failed test 4" << endl;

    A.findPrev(15);
    if (A.position() != 0)
      cout << "failed test 5" << endl;

    A.moveBack();
    if (A.position() != 5)
      cout << "failed test 6" << endl;
    A.eraseBefore();
    A.eraseBefore();
    A.eraseBefore();
    A.eraseBefore();
    A.eraseBefore();
    if (A.position() != 0)
    cout << "failed test 7" << endl;

    return EXIT_SUCCESS;
}