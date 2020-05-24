#include <iostream>
using namespace std;

void bubble_sort(int *a, int n){
    // length of unsorted array == 1
    if(n == 1){
        return;
    }
    for(int j=0; j<n-1; j++){
        if(a[j] > a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    bubble_sort(a,n-1);
}

void bubble_sort_recursive(int *a, int j, int n){
    // two loops two base cases

    // Ist base case so always return
    if(n==1){
        return;
    }

    // 2nd base case so always returns
    if(j == n-1){
        return bubble_sort_recursive(a,0,n-1);
    }

    if(a[j]>a[j+1]){
        swap(a[j],a[j+1]);
    }
   
    bubble_sort_recursive(a,j+1,n);
}


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // bubble_sort(a,n);
    // for(int i=0; i<n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    bubble_sort_recursive(a,0,n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}