#include <iostream>
using namespace std;

string eveodd(int n){
    if(n & 1){
        return "Odd";
    }
    return "even";
}

int getbit(int n, int i){
    int mask = 1 << i;
    if((n & mask) > 0){
        return 1;
    }
    return 0;
}

int setbit(int n, int i){
    int mask = 1 << i;
    int result = n | mask;
    return result;
}

int clearbit(int n, int i){
    int mask = ~(1 << i);
    return n & mask;
}

int updatebit(int n, int i, int v){
    int mask = ~(1 << i);
    int cleared_n = mask & n;
    int result = cleared_n | (v << i);
    return result;
}

int clearLastIbits(int n, int i){
    int mask = -1 << i;
    int result = mask & n;
    return result;
}

int clearRangeFromIToJ(int n, int i, int j){
    int a = -1 << (i+1);
    int b = ~(-1 << j);
    int mask = a | b;
    int result = mask & n;
    return result;

}

int main(){
    int n;
    int i;
    cin >> n >> i;
    // int v = 1;
    // cout << eveodd(n) << endl;
    // cout << getbit(n,i)<< endl;
    // cout << setbit(n,i)<< endl;
    // cout << clearbit(n,i)<< endl;
    // cout << updatebit(n,i,v)<< endl;
    // cout << clearLastIbits(n,i);
    cout << clearRangeFromIToJ(n,7,3);

}