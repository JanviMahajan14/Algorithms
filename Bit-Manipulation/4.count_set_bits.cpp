// given a integer N find number of set bits in it

#include<iostream>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n > 0){
        if(n&1){
            cnt++;
        }
        n = n >> 1; //right shift one : discard one bit
    }
    return cnt;
}

int FastcountSetBits(int n){
    int ans = 0;
    while( n > 0){
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    cout << FastcountSetBits(n) << endl;
    cout << __builtin_popcount(n) << endl;
}