// Check if a array is sorted
#include <iostream>
using namespace std;

bool sort_recursive(int a[],int start, int end){
    if(start == end){
        return true;
    }
    if(a[start] > a[start+1]){
        return false;
    }
    else{
        start++;
    }
    sort_recursive(a,start,end);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << sort_recursive(a,0,n-1);
}