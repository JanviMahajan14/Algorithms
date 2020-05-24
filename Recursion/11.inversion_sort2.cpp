#include <iostream>
using namespace std;

int cross_inversion(int *a, int start, int end){
    int temp[100];
    int i = start;
    int mid = (start+end)/2;
    int j = mid+1;
    int k = start;
    int cnt = 0;

    while(i<=mid && j<=end){
        if(a[i] < a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
            cnt += mid-i+1;
        }
    }

    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=end){
        temp[k++]=a[j++];
    }

    for(int i=start; i<k; i++){
        a[i] = temp[i];
    }

    return cnt;
}

int inversion_sort(int *a, int start, int end){
    if(start >= end){
        return 0;
    }
    int mid = (start+end)/2;
    int x = inversion_sort(a,start,mid);
    int y = inversion_sort(a,mid+1,end);
    int z = cross_inversion(a,start,end);
    return x+y+z;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << inversion_sort(a,0,n-1);
}