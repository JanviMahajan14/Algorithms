// finding a^b efficiently using recursion

// we know a^b = a*(a^b-1)

#include <iostream>
using namespace std;

// O(n)
int powerup(int a, int b){
    if(b == 0){
        return 1;
    }
    else{
        return a * powerup(a, b-1);
    }
}

// O(logn): Solving two sub problems
int fastpower(int a, int b){
    if(b == 0){
        return 1;
    }
    int result = fastpower(a,b/2);
    result = result * result;

    if(b%2 == 0){
        return result;
    }
    else{
        return a*result;
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << powerup(a,b) << endl;
    cout << fastpower(a,b);
}