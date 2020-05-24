#include <iostream>
using namespace std;

int ladder(int n){
    if(n == 0){
        return 1;
    }
    else if(n <= 2){
        return n;
    }
    return ladder(n-1)+ ladder(n-2) + ladder(n-3);

    // in case of K steps
    // int res;
    // for(int i=1; i<=k; i++){
    //     res += ladder(n-i);
    // }
    // return res;
}

int main(){
    int n;
    cin >> n;
    cout << ladder(n);
}