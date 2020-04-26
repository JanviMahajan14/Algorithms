#include <iostream>
using namespace std;

int main(){
    int n,r,s;
    cin >> n;
    r = n-1, s = 0;
    int a[n][n];int rotate[n][n] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rotate[r--][s] = a[i][j];
        }
        r = n-1;
        s++;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << rotate[i][j] << " ";
        }
        cout << endl;
    }
}
