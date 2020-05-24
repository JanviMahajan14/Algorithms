#include <iostream>
using namespace std;

void merge(int *a, int start, int mid, int end){
    int temp[100];
    int i = start;
    int j = mid+1;
    int k = start;

    while(i<=mid && j<=end){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=end){
        temp[k++] = a[j++];
    }
    for(int i=start; i<k; i++){
        a[i] = temp[i];
    }

}

void merge_sort(int *a, int start, int end){
   if(start == end){
       return;
   }
   int mid = (start + end)/2;
   merge_sort(a,0,mid);
   merge_sort(a,mid+1,end);
   merge(a,start,mid,end);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    merge_sort(a,0,n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}