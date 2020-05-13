// Given a array in which every element occurs twice except one. Find that one element

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int res=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        res = res ^ a[i];
    }
    cout << res;
}