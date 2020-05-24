#include <iostream>
using namespace std;

int max_array(int a[], int s, int e){
    if(s > e){
        return a[e];
    }
    int ans = max_array(a,s+1,e);

    if(a[s] > ans){
        return a[s];
    }
    return ans;
}

int min_array(int a[], int s, int e){
    if(e == 0){
        return a[e];
    }
    int ans = min_array(a,s,e-1);

    if(ans > a[e]){
        return a[e];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << max_array(a,0,n-1) << endl;
    cout << min_array(a,0,n-1);
}