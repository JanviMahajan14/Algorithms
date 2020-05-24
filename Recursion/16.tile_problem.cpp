#include <iostream>
using namespace std;

int no_of_ways(int n){
    if(n <= 3){
        return 1;
    }
    return  no_of_ways(n-1) + no_of_ways(n-4);
}

int main(){
    int n;
    cin >> n;
    cout << no_of_ways(n);
}

