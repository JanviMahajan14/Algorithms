#include <iostream>
using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    int ** ptr = new int*[r];

    for(int i=0; i<r; i++){
        ptr[i] = new int[c]; 
    }

    // Taking input values and printing it
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> ptr[i][j];
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << ptr[i][j];
        }
    }
}