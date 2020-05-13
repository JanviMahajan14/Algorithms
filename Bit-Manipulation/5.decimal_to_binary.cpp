#include<iostream>
using namespace std;

void convertToBinary(int n){
    if(n == 0){
        return;
    }
    convertToBinary(n >> 1);
    cout << (n&1);
}

int main(){
    int n;
    cin >> n;
    convertToBinary(n);
}