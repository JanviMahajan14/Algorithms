#include <iostream>
#include <algorithm>
using namespace std;

bool checkconfig(int book[], int n, int m, long long int mid_num){
    long long int sum=0,cnt=1; //Nice aproach if we take cnt = 1 (initially)
    for(int i=0;i<n;i++){
        sum = sum + book[i];
        if(sum > mid_num){
            cnt++;
            sum = book[i];
        }
    }
    // need to increase the pages if we get cnt > requrired no of students
    if(cnt > m){
        return false;
    }
    return true;
}

int allocate_books(int book[], int n, int m, long long int sum){
    if(n < m){
        return -1;
    }
    long long int start = book[n-1]; // got stuck if I start with 0 start with a[n-1]
    long long int end = sum;
    long long int result, mid;
    while(start <= end){
        mid = (start+end)/2;
        if (checkconfig(book,n,m,mid)){
            // if possible find result but we need to find min result
            result = mid;
            end = mid - 1;
        } 
        else {
            start = start + 1;
        }
           
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int book[n];
        sort(book,book+n);
        long long int totalsum = 0;
        for(int i=0; i<n; i++){
            cin >> book[i];
            totalsum = totalsum + book[i];
        }
        cout << allocate_books(book,n,m,totalsum)<< endl;
    }
}