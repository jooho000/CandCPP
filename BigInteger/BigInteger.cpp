/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA6
* BigInteger.cpp
* BigInteger ADT
***/ 
#include "BigInteger.h"
#include<iostream>
#include<string>
#include<stdexcept>

const long BASENUM = 1000000000; //base billion
const long POWER = 9;

BigInteger::BigInteger() {
    signum = 0;
    digits = List();
}

BigInteger::BigInteger(long x) {
    digits = List();
    if (x==0) {
        signum = 0;
        return;
    } else if (x > 0) {
        signum = 1;
    } else {
        signum = -1;
    }
    long myNum = abs(x);
    while (myNum > 0) {
        digits.insertAfter(myNum % BASENUM);
        myNum /= BASENUM;
    }
}

BigInteger::BigInteger(std::string s) {
    digits = List();
    signum = 0;
    if (s.length() == 0) {
        return;
    }
    if (s[0] == '-') {
        signum = -1;
        s = s.substr(1);
    } else if (s[0] == '+'){
        signum = 1;
        s = s.substr(1);
    } else {
        signum = 1;
    }
    while (s[0] == '0') {
        s = s.substr(1);
    }

    digits.moveFront();
    std::string tempString;
    ListElement tempElem;
    while (s.length() > POWER) {
        tempString = s.substr(s.length()-POWER);
        tempElem = std::stod(tempString);
        s = s.substr(0,s.length()-POWER);
        digits.insertAfter(tempElem);
    }
    digits.moveFront();
    if (s.length() != 0) {
        tempElem = std::stod(s);
        digits.insertAfter(tempElem);
    }
}

BigInteger::BigInteger(const BigInteger& N) {
    signum = N.signum;
    digits = N.digits;
}

void scalarMultiply(List &L, ListElement x) {
    L.moveFront();
    for (int i = 0; i < L.length(); i++) {
        ListElement temp = L.peekNext();
        temp *= x;
        L.setAfter(temp);
        L.moveNext();
    }
}

int normalize(List &L) {
    int newSign = 1;
    ListElement carry = 0;
    L.moveBack();

    for (int i = 0; i < L.length(); i++) {
        ListElement temp = L.movePrev() + carry;
        if (temp >= BASENUM) {
            carry = temp;
            carry /= BASENUM;
            temp %= BASENUM;
        } else if (temp < 0) {
            carry = 0;
            while (temp < 0) {
                temp += BASENUM;
                carry--;
            }
        } else {
            carry = 0;
        }
        L.setAfter(temp);
    }

    if (carry != 0) {
        L.moveFront();
        L.insertAfter(carry);
    }

    if (L.length() > 0 && L.front() < 0) {
        scalarMultiply(L,-1);
        normalize(L);
        newSign = -1;
    }

    while (L.length() > 0 && L.front() == 0 ) {
        L.moveFront();
        L.eraseAfter();
    }
    if (L.length() == 0) {
        newSign = 0;
    }
    return newSign;
}

void shiftList(List &L) {
    L.moveBack();
    L.insertBefore(0);
}

int BigInteger::sign() const {
    return signum;
}

int BigInteger::compare(const BigInteger &N) const {

    if (signum != N.signum) { //check when signs do not match
        if (signum == 1) {
            return 1;
        } else if (signum == 0) {
            if (N.signum == 1) {
                return -1;
            } else {
                return 1;
            }
        } else {
            return -1;
        }
    } // end of check when sign does not match

    if (digits.length() != N.digits.length()) { //check when length do not match
        if (digits.length() > N.digits.length()) {
            if (signum == -1) {
                return -1;
            } else {
                return 1;
            }  
        } else {
            if (signum == -1) {
                return 1;
            } else {
                return -1;
            } 
        }
    } // end when length do not match

    List currCopy = digits;
    List NCopy = N.digits;
    currCopy.moveBack();
    NCopy.moveBack();

    for (int i = 0; i < currCopy.length(); i++) {
        ListElement temp = currCopy.movePrev();
        ListElement temp2 = NCopy.movePrev();

        if (temp > temp2) {
            if (signum == 1) {
                return 1;
            } else {
                return -1;
            } 
        } else if (temp < temp2) {
            if (signum == 1) {
                return -1;
            } else {
                return 1;
            } 
        }
    }

    return 0;
}

void BigInteger::makeZero() {
    scalarMultiply(digits,3);
    digits.clear();
    signum = 0;
}

void BigInteger::negate() {
    signum *= -1;
}

int sumLists(List& S, List A, List B, ListElement x) {
    int newSign = 1;
    List shortList;
    if (A.length() > B.length()) {
        shortList = B;
        scalarMultiply(shortList,x);
        S = A;
    } else {
        shortList = A;
        S = B;
        scalarMultiply(S,x);
    }

    S.moveBack();
    shortList.moveBack();
    for (int i = 0; i < shortList.length(); i++) {
        ListElement temp = S.movePrev() + shortList.movePrev();
        S.setAfter(temp);
    }
    newSign = normalize(S);

    return newSign;
}

BigInteger BigInteger::add(const BigInteger& N) const {
    BigInteger result;
    result.signum = signum;
    List temp = digits;

    if (signum == 1 && N.signum == 1) {
        result.signum *= sumLists(result.digits, temp, N.digits, 1);
    } else if (signum == 1 && N.signum == -1) {
        result.signum *= sumLists(result.digits, temp, N.digits, -1);
    } else if (signum == -1 && N.signum == -1) {
        result.signum *= sumLists(result.digits, temp, N.digits, 1);
    } else if (signum == -1 && N.signum == 1) {
        result.signum *= sumLists(result.digits, temp, N.digits, -1);
    }
    return result;
}

BigInteger BigInteger::sub(const BigInteger& N) const {
    BigInteger result = N;
    result.negate();
    return add(result);
}

BigInteger BigInteger::mult(const BigInteger& N) const {
    List longer, shorter;
    BigInteger result, tempInteger;
    result.signum = signum * N.signum;
    if (result.signum == 0) {
        return result;
    }

    if (digits.length() >= N.digits.length()) {
        longer = digits;
        shorter = N.digits;
    } else {
        longer = N.digits;
        shorter = digits;
    }

    shorter.moveBack();
    for (int i = 0; i < shorter.length(); i++) {
        tempInteger.digits = longer;
        tempInteger.signum = 1;
        ListElement temp = shorter.movePrev();
        scalarMultiply(tempInteger.digits, temp);
        normalize(tempInteger.digits);
        for (int j = 0; j < i; j++) {
            shiftList(tempInteger.digits);
        }
        result = result.add(tempInteger);
    }
    result.signum = signum * N.signum;
    return result;
}

std::string BigInteger::to_string() {
    std::string myString = "";
    digits.moveFront();
    if (signum == 0) {
        return "0";
    }

    for (int i = 0; i < digits.length(); i++) {
        ListElement tempElem = digits.moveNext();
        std::string tempString = std::to_string(tempElem);
        if (tempString.length() == POWER) {
            myString += tempString;
        } else {
            while (tempString.length() < POWER) {
                tempString.insert(0,"0");
            }
            myString += tempString;
        }
    }
    while (myString[0] == '0' && myString.length() != 1) {
        myString = myString.substr(1);
    }

    if (signum == -1) {
        myString = "-" + myString;
    }

    return myString;
}

std::ostream& operator<<( std::ostream& stream, BigInteger N ) {
    return stream << N.to_string();
}

bool operator==( const BigInteger& A, const BigInteger& B ) {
    bool result;
    if (A.compare(B) == 0) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool operator<( const BigInteger& A, const BigInteger& B ) {
    bool result;
    if (A.compare(B) == -1) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool operator<=( const BigInteger& A, const BigInteger& B ) {
    bool result;
    if (A.compare(B) == -1 || A.compare(B) == 0) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool operator>( const BigInteger& A, const BigInteger& B ) {
    bool result;
    if (A.compare(B) == 1) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

bool operator>=( const BigInteger& A, const BigInteger& B ) {
    bool result;
    if (A.compare(B) == 1 || A.compare(B) == 0) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

BigInteger operator+( const BigInteger& A, const BigInteger& B ) {
    return A.add(B);
}

BigInteger operator+=( BigInteger& A, const BigInteger& B ) {
    BigInteger temp = A.add(B);
    A = temp;
    return temp;
}

BigInteger operator-( const BigInteger& A, const BigInteger& B ) {
    return A.sub(B);
}

BigInteger operator-=( BigInteger& A, const BigInteger& B ) {
    BigInteger temp = A.sub(B);
    A = temp;
    return temp;
}

BigInteger operator*( const BigInteger& A, const BigInteger& B ) {
    return A.mult(B);
}

BigInteger operator*=( BigInteger& A, const BigInteger& B ) {
    BigInteger temp = A.mult(B);
    A = temp;
    return temp;
}