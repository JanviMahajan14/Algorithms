/* Finding first ocurrence of a number by linear search implemntation using recursion 
since it is a unsorted array*/

#include<iostream>
using namespace std;

int linear_search(int a[], int start, int end, int key){
    if(start > end){
        return -1;
    }
    if(a[start]==key){
        return start;
    }
    start++;
    linear_search(a,start,end,key);
}

// important
int upper_bound(int a[], int start, int end, int key){
    if(start > end){
        return -1;
    }
    int i = upper_bound(a,start+1,end,key);

    // only implement once
    if(i == -1){
        if(a[start]==key){
            i = start;
        }
    }

    return i;
    
}

void all_occurrence(int b[], int start, int end, int key){
    if(start > end){
        return;
    }
    all_occurrence(b,++start,end,key);

    if(b[start]==key){
        cout << start << " ";
    }
    return;
}

int main(){
    int a[] = {2,4,7,7,7,8,10};
    int b[] = {5,9,3,2,5,9,8};
    int key;
    cin >> key;
    cout << linear_search(a,0,6,key) << endl;
    cout << upper_bound(b,0,6,9) << endl;
    all_occurrence(b,0,6,9);
}