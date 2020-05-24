#include <iostream>
#include <math.h>
using namespace std;

// O(root N)
void factors(int n){
    int m = pow(n,0.5);
    for(int i=1; i<=m; i++){
        if(n%i == 0){
            cout << i << " " << n/i << " ";
        }
    }
}

void fast_factors(int n, int i){
    int m = pow(n,0.5);
    if(i > m){
        return;
    }
    else if(n%i == 0){
        cout << i << " " << n/i << " ";
    }
    fast_factors(n,i+1);
}

int main(){
    int n;
    cin >> n;
    factors(n);
    cout << endl;
    fast_factors(n,1);
}