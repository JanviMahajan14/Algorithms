// finding a^b efficiently using recursion
#include <iostream>
using namespace std;

int powerup(int a, int b){
    if(b == 0){
        return 1;
    }
    else{
        return a * powerup(a, b-1);
    }
}

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