// high > low < high > low < high > low
#include<iostream>
using namespace std;

void wave_sort(int *a, int n){
    // iterate only on even indexes
    for(int i=0; i<n; i+=2){
        if(i!=0 && a[i] < a[i-1]){
            swap(a[i],a[i-1]);
        }
        if(i!=(n-1) && a[i] < a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    wave_sort(a,n);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}