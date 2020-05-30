#include <iostream>
using namespace std;

int find_houses(int a[], int n, int b){
    if(b<0){
        return -1;
    }
    if(n==0 || b==0){
       return 0; 
    }
    int include = 1 + find_houses(a,n-1,b-a[n-1]);
    int exclude = find_houses(a,n-1,b);
    return max(include,exclude);
}

int main(){
    int t;
    cin >> t;
    for(int k=1; k<=t; k++){
        int n,b;
        cin >> n >> b;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int ans = find_houses(a,n,b);
        cout << "Case #" << k << ": " <<  ans << endl;
    }
}