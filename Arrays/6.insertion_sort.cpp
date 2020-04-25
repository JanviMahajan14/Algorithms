#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void insertion_sort(int a[], int n){
    for(int i=1; i<n; i++){
         int t = a[i];
        for(int j=i-1; j>=0; j--){
            if(a[j] > t){
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    insertion_sort(a,n);
}