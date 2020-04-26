/* Since the first method takes extra space we can reduce it O(1) space by reversing 
the rows of the matrxix and then taking the transpose: Diagonal elements remain same
a[i][j] swaps with a[j][i]*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 
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
        // Reverse the rows using STL where a[i] is the row pointer
        reverse(a[i], a[i] + n);
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i < j){
                swap(a[i][j], a[j][i]);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
