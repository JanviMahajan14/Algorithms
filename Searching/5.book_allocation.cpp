#include <iostream>
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
    if(cnt == m){
        return true;
    }
    return false;
}

int allocate_books(int book[], int n, int m, long long int sum){
    if(n < m){
        return -1;
    }
    int start = 0;
    int end = sum;
    long long int a[sum+1];
    for(int i=0; i<=sum; i++){
        a[i] = i;
    }
    int result, mid;
    while(start <= end){
        mid = (start+end)/2;
        if(checkconfig(book,n,m,a[mid])){
            result = a[mid];
            end = mid-1;
        }else{
            start = mid+1;
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
        long long int totalsum = 0;
        for(int i=0; i<n; i++){
            cin >> book[i];
            totalsum = totalsum + book[i];
        }
        cout << allocate_books(book,n,m,totalsum)<< endl;
    }
}