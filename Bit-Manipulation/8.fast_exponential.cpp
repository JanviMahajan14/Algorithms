#include <iostream>
using namespace std;

int fast_exponention(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b&1){
            ans = ans * (a*(b&1));
        }
        a = a*a;
        b = b >> 1;
    }
    return ans;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << fast_exponention(a,b);
}