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
    // Never do this just change the search space!
    // else{
    //     start++;
    // }
    sort_recursive(a,start+1,end);
    // cout << start << " " << end << endl;
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