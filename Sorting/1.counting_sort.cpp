#include<iostream>
using namespace std;

void count_sort(int *arr, int n){
    int largest = -1;
    for(int i=0; i<n; i++){
        largest = max(largest,arr[i]);
    }
    int freq[largest+1]={0};

    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    int j=0;
    for(int i=0; i<=largest; i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
}

int main(){
    int arr[6] = {23,90,57,45,1,8};;
    count_sort(arr,6);

    for(int i=0; i<6; i++){
        cout << arr[i] << " ";
    }
    // O(n+R)
}