// Finding square root of a num using binary search

#include <iostream>
using namespace std;

int square_root(int a[], int n){
    int start = 0, end = n-1, ans;

    while(start <= end){
        int mid = (start+end)/2;
        if(a[mid]*a[mid] == n ){
            return mid;
        }
        else if(a[mid]*a[mid] > n){
            end = mid-1;
        }
        // Can be possible it is the result but we want max posible no
        else{
            ans = mid;
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<=n; i++){
        a[i] = i;
    }
    cout << square_root(a,n);
}