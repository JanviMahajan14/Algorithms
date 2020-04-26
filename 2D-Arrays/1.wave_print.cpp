#include <iostream>
using namespace std;

int main(){
    int m,n,i;
    cin >> m >> n;
    int a[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for(int j=0; j<n; j++){
        if(j%2 == 0){
            i = 0;
        }
        else{
            i = m-1;
        }
       while(i < m && i >= 0){
            if(j%2 == 0){
                cout << a[i][j] << " ";
                i++;
            }
            else{
                cout << a[i][j] << " ";
                i--; 
            }
        }
    }
}
