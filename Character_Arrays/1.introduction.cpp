#include <iostream>
using namespace std;

int main(){

    //Stops when the input is \n
    char b[100];
    cin.getline(b,100);
    cout << b;

    // Stops at input is $ and not \n which is by default
    char a[100];
    cin.getline(a,100,'$');
    cout << a;

    // Same application for 2D-arrays also
    char c[100][100];
    int i=0;
    cin.getline(c[i], 100);
    cout << c[i];

}