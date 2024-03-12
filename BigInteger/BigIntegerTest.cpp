/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA6
* BigIntegerTest.cpp
* BigInteger test cases
***/ 
#include "BigInteger.h"

using namespace std;

int main() {
    //BigInteger A = BigInteger("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    //BigInteger B = BigInteger("22222222222222222222222222222222222");
    BigInteger A = BigInteger("-0000000000041085449");
    BigInteger B = BigInteger("6402779357");
    BigInteger C = BigInteger();
    BigInteger D = BigInteger("-123123123123123123");
    BigInteger E = BigInteger(12345678);

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "D: " << D << endl;
    cout << "E: " << E << endl;

    BigInteger F = A + B;
    cout << "A+B: " << F << endl;
    F = A - B;
    cout << "A-B: " << F << endl;
    BigInteger G = A * B;
    cout << "A * B: " << G << endl;
    G = A * A;
    cout << "A * A: " << G << endl;
    BigInteger temp = BigInteger(3);
    BigInteger temp2 = BigInteger(2);
    G = A * temp;
    cout << "A * 3: " << G << endl;
    B = B * temp2;
    cout << "B * 2: " << B << endl;
    G = G -B;
    cout << "3A - 2B: " << G << endl;
    bool trueOrFalse = A > B;
    cout << "A > B: " << trueOrFalse << endl;
    trueOrFalse = A < B;
    cout << "A < B: " << trueOrFalse << endl;
    trueOrFalse = A == A;
    cout << "A == A: " << trueOrFalse << endl;
    trueOrFalse = B == B;
    cout << "B == B: " << trueOrFalse << endl;
    trueOrFalse = D > E;
    cout << "D > E: " << trueOrFalse << endl;
    trueOrFalse = E <= A;
    cout << "E <= A: " << trueOrFalse << endl;
    trueOrFalse = E == B;
    cout << "E == B: " << trueOrFalse << endl;
    trueOrFalse = A <= A;
    cout << "A <= A: " << trueOrFalse << endl;

    BigInteger temp3 = BigInteger(9);
    BigInteger temp4 = BigInteger(16);
    cout << "9A^4 + 16B^5: " << (A*A*A*A*temp3) + (B*B*B*B*B*temp4) << endl;
    return EXIT_SUCCESS;
}