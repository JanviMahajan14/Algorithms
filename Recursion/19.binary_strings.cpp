#include <iostream>
using namespace std;

int count_string(int n){
    if(n==0){
        return 1;
    }
    else if(n==1){
        return 2;
    }
    return count_string(n-1)+count_string(n-2);
}

int main(){
    int n;
    cin >> n;
    cout << count_string(n);
}