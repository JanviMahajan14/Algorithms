#include <iostream>
using namespace std;

bool possible(long long n, long long m, long long x, long long y, long long mid){
    if(mid*x <= ( m +(n-mid)*y)){
        return true;
    }
    return false;
}

long long findstudents(long long n, long long m, long long x, long long y){
    long long int start = m/x,mid,res;
    long long int end = n;
    while(start <= end){
        mid = (start+end)/2;
        if(possible(n,m,x,y,mid)){
            res = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return res;
}

int main(){
    long long int n,m,x,y,ans;
    cin >> n >> m >> x >> y;
    cout << findstudents(n,m,x,y);
}
