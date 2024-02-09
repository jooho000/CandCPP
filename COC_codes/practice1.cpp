#include<iostream>
using namespace std;

int getInput();
void getValues(int);

int myArray[5] = {2,5,4,2,0};
int result[2] = {0,0};

int main() {
    int desiredNum = getInput();
    getValues(desiredNum);
    cout << "[" << result[0] << ", " << result[1] << "]";
    return 0;
}

int getInput() {
    cout << "enter desired value: ";
    int myNum;
    cin >> myNum;
    return myNum;
}

void getValues(int target) {
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if ( myArray[i] + myArray[j] == target) {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
        
    }
    
}