#include <iostream>
using namespace std;

int binary_search (int *a, int s, int e, int key){
    for(int i=0; i<=e ; i++){
        int mid = (e-s)/2 + s;
        if(*(a+mid) == key){
            return mid;
        }
        else if(*(a+mid) > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){
    int n, key;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> key;
    cout << "Element is present at " << binary_search(a,0,n-1,key);
}