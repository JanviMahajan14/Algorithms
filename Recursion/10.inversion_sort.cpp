#include <iostream>
using namespace std;

int inversion_sort(int a[], int i, int j, int cnt, int n){
    if(i == n-1){
        return cnt;
    }
    if(j == n){
        return inversion_sort(a,i+1,i+2,cnt,n);
    }
    if(a[i] > a[j]){
        cnt++;
    }
    inversion_sort(a,i,j+1,cnt,n);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << inversion_sort(a,0,1,0,n);
}