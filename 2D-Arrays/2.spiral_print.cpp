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
    // Four pointers
    int start_row=0;
    int end_row = m-1;
    int start_col = 0;
    int end_col = n-1;

    while(start_row <= end_row && start_col < end_col){
        for(int i=start_row, j=start_col; j<=end_col ;j++){
            cout << a[i][j] << " ";
        }
        start_row++;

        for(int j=end_col, i=start_row; i<=end_row; i++){
            cout << a[i][j] << " ";
        }
        end_col--;

        for(int j=end_col, i=end_row; j>=start_col; j--){
            cout << a[i][j] << " ";
        }
        end_row--;

        for(int i=end_row, j=start_col; i>=start_row; i--){
            cout << a[i][j] << " ";
        }
        start_col++;
    }
}
