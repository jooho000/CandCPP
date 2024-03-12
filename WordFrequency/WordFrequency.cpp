/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA8
* WordFrequency.cpp
* Dictionary Client for WordFrequency
***/ 
#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <string>

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

    Dictionary A = Dictionary();
    int token_count, line_count;
    size_t begin, end, len;
    string line;
    string tokenBuffer;
    string token;
    string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$^&*()%-_=+0123456789"; 
    //string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$^&*()-_=+0123456789";
    while( getline(inFile, line) )  {
        line_count++;
        len = line.length();
      
        // get tokens in this line
        token_count = 0;
        tokenBuffer = " ";

        // get first token
        begin = min(line.find_first_not_of(delim, 0), len);
        end   = min(line.find_first_of(delim, begin), len);
        token = line.substr(begin, end-begin);
        for (size_t i = 0; i < token.length(); i++) {
            token[i] = tolower(token[i]);
        }
        if (A.contains(token)) {
            int tempVal = A.getValue(token);
            A.setValue(token, tempVal + 1);
        } else {
            A.setValue(token,1);
        }
      
        while( token!="" ){  // we have a token
            // update token buffer
            tokenBuffer += "   "+token+"\n";
            token_count++;

            // get next token
            begin = min(line.find_first_not_of(delim, end+1), len);
            end   = min(line.find_first_of(delim, begin), len);
            token = line.substr(begin, end-begin);
            for (size_t i = 0; i < token.length(); i++) {
                token[i] = tolower(token[i]);
            }     

            if (A.contains(token)) {
                int tempVal = A.getValue(token);
                A.setValue(token, tempVal + 1);
            } else {
                A.setValue(token,1);
            }
        }

    }
    outFile << A << endl;
    A.clear();
    return EXIT_SUCCESS;
}