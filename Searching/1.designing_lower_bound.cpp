// designing a lower bound and upper bound function in a sorted array using binary search
#include <iostream>
using namespace std;

int lowerbound(int a[], int start, int end, int key){
    int mid;
    int ans = -1;
    while(start <= end){
        mid = (start+end)/2;
        if(a[mid] == key){
            ans = mid;
            end = mid -1;
        }
        else if(a[mid] > key){
            end = mid-1;
        }
        else{
            start = mid +1;
        }
    }
    return ans;
}

int upperbound(int a[], int start, int end, int key){
    int mid;
    int ans = -1;
    while(start <= end){
        mid = (start+end)/2;
        if(a[mid] == key){
            ans = mid;
            start = mid +1;
        }
        else if(a[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << lowerbound(a,0,n-1,key) << " " << upperbound(a,0,n-1,key) << endl;
}
