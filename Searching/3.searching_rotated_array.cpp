// Given a rotated array, search a given element using binary search

#include <iostream>
using namespace std;

int search_rotation(int a[], int start, int end, int key){
    int mid;
    while(start <= end){
        mid = (start + end)/2;
        if(a[mid]==key){
            return mid;
        }
        // check if the first part of the array is sorted or not
        else if(a[mid] >= a[start]){
            //check if key is a part of sorted or unsorted array
            if(a[start]<=key && key<a[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        //second part of array is sorted
        else{
            //check if the element lies in the sorted part of the array
            if (a[mid]<=a[end])
            {
                start = mid+1;
            }
            else{
                end = mid -1;
            }
        }
    }
    return -1;
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
    cout << search_rotation(a,0,n-1,key);

}
