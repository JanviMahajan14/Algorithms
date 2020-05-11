#include <iostream>
#include <algorithm>
using namespace std;

bool cowsRakhPaye(long long int a[], int n, int cows, long long int mid){
    int cnt = 1;
    long long int current_cow = a[0];
        for(int j=1; j<n; j++){
            if(a[j]-current_cow >= mid){
                current_cow = a[j];
                cnt++;
            }
        }
    if(cnt < cows){
        return false;
    }
    return true;
}

long long int place_cows(long long int a[], int n, int cows){
    //Hypothetical Search space between the cows
    long long int start = 0;
    long long int end = a[n-1]-a[0];
    long long int result;
    while(start <= end){
        long long int mid = (start+end)/2;
        if(cowsRakhPaye(a,n,cows,mid)){
            result = mid;
            start = mid+1;

        } else {
            //No need to increase gap..so end = mid-1
            end = mid -1;
        }
    }
    return result;
}

int main(){
    // No of stalls
    int n;
    cin >> n;
     // No of cows
    int cows;
    cin  >> cows;
    long long int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cout << place_cows(a,n,cows);
}