#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void selection_sort(int a[], int n){
    for(int i=0; i<n; i++){
      int min = i;
      for(int j=i+1; j<n; j++){
          if(a[j] < a[min]){
              min = j;
          }
      }
        swap(a[min],a[i]);
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
    selection_sort(a,n);
}