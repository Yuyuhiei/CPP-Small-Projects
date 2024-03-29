#include <iostream>
using namespace std;

bool validNum(int a){
    if(a % 2 != 0 && a >= 3 && a <= 15)
        return true;
    else
        return false;
}

void printSum(int **magicArr, int size){
//checking

    //print sum of rows
    cout<< "Sum of rows: ";
    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = 0; j < size; j++){
            sum += magicArr[i][j];
        }
        cout<< sum<<' ';
    }

    //print sum of columns
    cout<<'\n'<< "Sum of columns: ";
    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = 0; j < size; j++){
            sum += magicArr[j][i];
        }
        cout<< sum<<' ';
    }

    //print sum of Diagnols Top Left to Bottom Right
    cout<<'\n'<< "Sum of diagonals: ";
    int diagNeg = 0;
    for(int i = 0; i < size; i++){
        diagNeg += magicArr[i][i];
    }
    cout<< diagNeg<<' ';

    //print sum of Diagnols Bottom Left to Top Right
    int diagPos = 0;
    for(int i = 0, j = size - 1; i < size; i++, j--){
        diagPos += magicArr[i][j];
    }
    cout<< diagPos<<' ';
}

void magic(int **magicArr, int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            //magic square algorithm
            magicArr[i][j] = ((i + j + 1 + (size/2)) % size) + ((i + 2*j +1) % size) + 1;
        }
    }

    //printing
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout<< magicArr[i][j]<<'\t'; }
        cout<< endl; }

    printSum(magicArr, size);

}

int main(){

    cout<< "Please input an odd integer" << '\n';
    int size;
    cin >> size;

    //making two dimensional dynamic array
    int **magicArr =  new int *[size];
    for(int i = 0; i < size; i++){
        magicArr[i] = new int[size];
    }

    //Checking if input is valid
    bool isValid = validNum(size);
    if (isValid) {
        magic(magicArr, size);
    } else {
        cout<< "The number you entered was not valid";
    }

    //deleting two dimensional algorithm
    for(int i = 0; i < size; i++){
        delete[] magicArr[i];
    }
    delete [] magicArr;

    return 0;
}
