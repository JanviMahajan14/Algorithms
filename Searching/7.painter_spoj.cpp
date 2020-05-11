#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(long long int a[], long long mid,long long n, long long k, long long t){
    long long int painter = 1,sum=0;
    for(int i=0; i<n; i++){
        sum = sum + a[i]*t;
        if(sum > mid){
            painter++;
            sum = a[i]*t;
        }
    }
    if(painter > k ){
        return false;
    }
    return true;
}

long long int minpainter(long long int a[], long long int start, long long int end, long long n, long long k,long long t){
    long long int mid, result;
    while(start <= end){
        mid = (start+end)/2;
        if(isPossible(a,mid,n,k,t)){
            result = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return result;
}

int main(){
    long long int n,k,t;
    cin >> n >> k >> t;
    long long int a[n],maxTime=0,large = -1;
    // We can't sort the array as the tiles are contingous so we use other way to find max value - was Stuck
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i]*t>large){
            large = a[i]*t;
        }
        maxTime = maxTime + a[i]*t;
    }
    cout << minpainter(a,large,maxTime,n,k,t)% 10000003;
}
