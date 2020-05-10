#include <iostream>
#include <algorithm>
using namespace std;

bool cowsRakhPaye(int a[], int n, int cows, int mid){
    int cnt = 1;
    int current_cow = a[0];
        for(int j=1; j<n; j++){
            if(a[j]-current_cow >= mid){
                current_cow = a[j];
                cnt++;
            }
            if(cnt == cows){
                return true;
            }
        }
    return false;
}

int place_cows(int a[], int n, int cows){
    //Hypothetical Search space
    int start = 0;
    int end = a[n-1]-a[0];
    int result;
    while(start <= end){
        int mid = (start+end)/2;
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
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // Sort the indexes of stalls may be given unsorted
    sort(a,a+n);
    // No of cows
    int cows;
    cin  >> cows;
    cout << place_cows(a,n,cows);
}