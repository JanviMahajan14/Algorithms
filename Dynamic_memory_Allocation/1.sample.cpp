#include<iostream>
using namespace std;

int main(){
    int a[] = {1,2,3,4};
    int *ptr = a;
    cout << *(ptr+1) << endl;
    cout << ptr[1] << endl;

    int *pointer = new int;
    cout << pointer << endl;
    *pointer = 12;
    cout << *pointer << endl;
}