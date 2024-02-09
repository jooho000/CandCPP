#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    double classSize, totalGrades = 0, classAvg;
    cout<<"Enter class size: ";
    cin >> classSize;
    int classSize1 = classSize;
    double *myArray = new double[classSize1];
    string filename = "class_grades.txt", tempString[3];
    
    for (int i = 0; i < classSize ; i++) {
        
        cout << "enter grade:" << endl;
        double tempMemory;
        cin >> tempMemory;
        myArray[i] = tempMemory;
        totalGrades = totalGrades + tempMemory;
        
    }
    
    classAvg = totalGrades/classSize;
    
    ofstream outFile;
    ifstream inFile;

    outFile.open(filename.c_str());
    if (outFile.fail()) {
        cout << "file not opened (outFile)" << endl;
        exit(1);
    }
    
    for (int j = 0; j < classSize1; j++) {
        outFile << myArray[j] << " ";
    }
    
    outFile << "\n" << classAvg;
    
    inFile.open(filename.c_str());
    if (inFile.fail()) {
        cout << "file not opened (infile)" << endl;
        exit(1);
    }
    
    getline(inFile,tempString[0]);
    getline(inFile,tempString[1]);
    
    double d = ((double)tempString[1].at(0)-48);
    cout << "the average is :" << d;
    
    return 0;
}