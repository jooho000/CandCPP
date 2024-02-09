#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void makeGradesFile(string);
void doBokow(string, string);
void doFallin(string, string);
void doKingsley(string, string);

int main() {
    string filename = "grades.txt", filename2 = "Bokow.txt", filename3 = "Fallin.txt", filename4 = "Kingsley.txt";

    makeGradesFile(filename);
    doBokow(filename, filename2);
    doFallin(filename, filename3);
    doKingsley(filename, filename4);

    cout << "grade files has been updated" << endl;

    return 0;
}

void makeGradesFile(string filename) {

    ofstream outFile;

     outFile.open(filename.c_str());
    if (outFile.fail()) {
        cout << "file not opened (outFile)" << endl;
        exit(1);
    }

    outFile << 2333021 << "\n" << "BOKOW, R." << "\n" << "NS201" << "\n" << 3 << "\n" << "A" << endl;
    outFile << 2333021 << "\n" << "BOKOW, R." << "\n" << "MG342" << "\n" << 3 << "\n" << "A" << endl;
    outFile << 2333021 << "\n" << "BOKOW, R." << "\n" << "FA302" << "\n" << 1 << "\n" << "A" << endl;
    outFile << 2574063 << "\n" << "FALLIN, D." << "\n" << "MK106" << "\n" << 3 << "\n" << "C" << endl;
    outFile << 2574063 << "\n" << "FALLIN, D." << "\n" << "MA208" << "\n" << 3 << "\n" << "B" << endl;
    outFile << 2574063 << "\n" << "FALLIN, D." << "\n" << "CM201" << "\n" << 3 << "\n" << "C" << endl;
    outFile << 2574063 << "\n" << "FALLIN, D." << "\n" << "CP101" << "\n" << 2 << "\n" << "B" << endl;
    outFile << 2663628 << "\n" << "KINGSLEY, B." << "\n" << "QA140" << "\n" << 3 << "\n" << "A" << endl;
    outFile << 2663628 << "\n" << "KINGSLEY, B." << "\n" << "CM245" << "\n" << 3 << "\n" << "B" << endl;
    outFile << 2663628 << "\n" << "KINGSLEY, B." << "\n" << "EQ521" << "\n" << 3 << "\n" << "A" << endl;
    outFile << 2663628 << "\n" << "KINGSLEY, B." << "\n" << "MK341" << "\n" << 3 << "\n" << "A" << endl;
    outFile << 2663628 << "\n" << "KINGSLEY, B." << "\n" << "CP101" << "\n" << 2 << "\n" << "B" << endl;

    outFile.close();
    cout << "grades.dat has been updated" << endl;
}

void doBokow(string filename, string filename2) {

    double courseGradeValue, creditConvertedToInteger, sumOfCredits = 0, sumForGPA = 0, GPA;
    string studentID[12], name[12], code[12], credit[12], grade[12], tempString;

    ifstream inFile;
    ofstream outFile2;

    outFile2.open(filename2.c_str());
    if (outFile2.fail()) {
        cout << "file not opened (outFile2)" << endl;
        exit(1);
    }

    inFile.open(filename.c_str());
    if (inFile.fail()) {
        cout << "file not opened (infile)" << endl;
        exit(1);
    }
    

    for (int i = 0 ; i < 12 ; i++) {

        getline(inFile, studentID[i]);
        getline(inFile, name[i]);
        getline(inFile, code[i]);
        getline(inFile, credit[i]);
        getline(inFile, grade[i]);

    }
        
    for (int j = 0 ; j < 3 ; j++) {

        if (grade[j] == "A") {
            courseGradeValue = 4;
        } else if (grade[j] == "B") {
            courseGradeValue = 3;
        } else if (grade[j] == "C"){
            courseGradeValue = 2;
        } else if (grade[j] == "D") {
            courseGradeValue = 1;
        } else {
            courseGradeValue = 0;
        }

        tempString = credit[j];
        creditConvertedToInteger = ((double)tempString.at(0)-48);
        sumForGPA += creditConvertedToInteger * courseGradeValue;
        sumOfCredits += creditConvertedToInteger;

    }

    GPA = sumForGPA / sumOfCredits;
    outFile2 << "Student Name: " << name[0] << endl;
    outFile2 << "Student ID Number: " << studentID[0] << "\n" << endl;
    outFile2 << "Course Code" << "      " << "Course Credits" << "      " << "Course Grade" << "\n" << endl;
    for (int j = 0 ; j < 3 ; j++) {
        outFile2 << code[j] << "                " << credit[j] << "                " << grade[j] << endl;
    }
    outFile2 << "\n";
    outFile2 << "Total Semester Grades Completed: " << sumOfCredits << endl;
    outFile2 << "Semester GPA: " << GPA;

    inFile.close();
    outFile2.close();
}

void doFallin(string filename, string filename2) {

    double courseGradeValue, creditConvertedToInteger, sumOfCredits = 0, sumForGPA = 0, GPA;
    string studentID[12], name[12], code[12], credit[12], grade[12], tempString;

    ifstream inFile;
    ofstream outFile2;

    outFile2.open(filename2.c_str());
    if (outFile2.fail()) {
        cout << "file not opened (outFile2)" << endl;
        exit(1);
    }

    inFile.open(filename.c_str());
    if (inFile.fail()) {
        cout << "file not opened (infile)" << endl;
        exit(1);
    }
    

    for (int i = 0 ; i < 12 ; i++) {
        
        getline(inFile, studentID[i]);
        getline(inFile, name[i]);
        getline(inFile, code[i]);
        getline(inFile, credit[i]);
        getline(inFile, grade[i]);
        
    }
    for (int j = 3 ; j < 7 ; j++) {

        if (grade[j] == "A") {
            courseGradeValue = 4;
        } else if (grade[j] == "B") {
            courseGradeValue = 3;
        } else if (grade[j] == "C"){
            courseGradeValue = 2;
        } else if (grade[j] == "D") {
            courseGradeValue = 1;
        } else {
            courseGradeValue = 0;
        }

        tempString = credit[j];
        creditConvertedToInteger = ((double)tempString.at(0)-48);
        sumForGPA += creditConvertedToInteger * courseGradeValue;
        sumOfCredits += creditConvertedToInteger;

    }

    GPA = sumForGPA / sumOfCredits;
    outFile2 << "Student Name: " << name[3] << endl;
    outFile2 << "Student ID Number: " << studentID[3] << "\n" << endl;
    outFile2 << "Course Code" << "      " << "Course Credits" << "      " << "Course Grade" << "\n" << endl;
    for (int j = 3 ; j < 7 ; j++) {
        outFile2 << code[j] << "                " << credit[j] << "                " << grade[j] << endl;
    }
    outFile2 << "\n";
    outFile2 << "Total Semester Grades Completed: " << sumOfCredits << endl;
    outFile2 << "Semester GPA: " << GPA;

    inFile.close();
    outFile2.close();
}

void doKingsley(string filename, string filename2) {

    double courseGradeValue, creditConvertedToInteger, sumOfCredits = 0, sumForGPA = 0, GPA;
    string studentID[12], name[12], code[12], credit[12], grade[12], tempString;

    ifstream inFile;
    ofstream outFile2;

    outFile2.open(filename2.c_str());
    if (outFile2.fail()) {
        cout << "file not opened (outFile2)" << endl;
        exit(1);
    }

    inFile.open(filename.c_str());
    if (inFile.fail()) {
        cout << "file not opened (infile)" << endl;
        exit(1);
    }

    for (int i = 0 ; i < 12 ; i++) {

        getline(inFile, studentID[i]);
        getline(inFile, name[i]);
        getline(inFile, code[i]);
        getline(inFile, credit[i]);
        getline(inFile, grade[i]);
        
    }
    for (int j = 7 ; j < 12 ; j++) {

        if (grade[j] == "A") {
            courseGradeValue = 4;
        } else if (grade[j] == "B") {
            courseGradeValue = 3;
        } else if (grade[j] == "C"){
            courseGradeValue = 2;
        } else if (grade[j] == "D") {
            courseGradeValue = 1;
        } else {
            courseGradeValue = 0;
        }

        tempString = credit[j];
        creditConvertedToInteger = ((double)tempString.at(0)-48);
        sumForGPA += creditConvertedToInteger * courseGradeValue;
        sumOfCredits += creditConvertedToInteger;

    }

    GPA = sumForGPA / sumOfCredits;
    outFile2 << "Student Name: " << name[7] << endl;
    outFile2 << "Student ID Number: " << studentID[7] << "\n" << endl;
    outFile2 << "Course Code" << "      " << "Course Credits" << "      " << "Course Grade" << "\n" << endl;
    for (int j = 7 ; j < 12 ; j++) {
        outFile2 << code[j] << "                " << credit[j] << "                " << grade[j] << endl;
    }
    outFile2 << "\n";
    outFile2 << "Total Semester Grades Completed: " << sumOfCredits << endl;
    outFile2 << "Semester GPA: " << GPA;

    inFile.close();
    outFile2.close();
}