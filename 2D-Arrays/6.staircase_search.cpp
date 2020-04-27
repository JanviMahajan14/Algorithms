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
    int key;
    cin >> key;

    // two pointers
    int left = n-1; /*column traversal*/
    int down = 0; /*row traversal*/

    while(left >= 0 && down < m){
        if(a[down][left] == key){
            cout << "Key is present";
            break;
        }
        else if(a[down][left] > key){
            left--;
        }
        else{
           down++;
        }
    }

    if(down == m || left < 0){
        cout << "No such element present";
    }
}
