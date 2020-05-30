// Sort an array of 0,1,2 in O(N)
#include<iostream>
using namespace std;

void dnf_sort(int *a, int n){
    int i=-1;
    int k=n;
    int j = 0;

    while(j<k){
        if(a[j]==0){
            i++;
            swap(a[j],a[i]);
        }
        if(a[j]==2){
            k--;
            swap(a[j],a[k]);
        }
        if(a[j]==1){
            j++;
        }
    }
}

int main(){
    int a[] = {1,0,2,0,0,0,1,1,2,0};
    dnf_sort(a,10);

    for(int i=0; i<10; i++){
        cout << a[i] << " ";
    }
}