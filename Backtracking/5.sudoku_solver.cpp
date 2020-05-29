#include<iostream>
#include<math.h>
using namespace std;

bool CanNumberPlaced(int sudoku[][9], int n, int i, int j, int k){
    // Along the row
    for(int col=0; col<j; col++){
        if(sudoku[i][col]==k){
            return false;
        }
    }

    // Along the col
    for(int row=0; row<i; row++){
        if(sudoku[row][j]==k){
            return false;
        }
    }

    // Along the subgrid
    int rn = sqrt(n);
    int x = (i/rn)*rn;
    int y = (j/rn)*rn;

    for(int t=x;t<(x+rn); t++){
        for(int u=y; u<(y+rn); u++){
            if(sudoku[t][u]==k){
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int sudoku[][9], int n, int i, int j){
    if(i==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    if(j==n){
        // Write return in case of calling the recursive fn in a base/end-points case
        return solve_sudoku(sudoku,n,i+1,0);
    }
    if(sudoku[i][j]!=0){
        return solve_sudoku(sudoku,n,i,j+1);
    }

    // recursive case
    for(int k=1; k<=9; k++){
        if(CanNumberPlaced(sudoku,n,i,j,k)){
            sudoku[i][j] = k;
            bool isSolved = solve_sudoku(sudoku,n,i,j+1);
            if(isSolved){
                return true;
            }
            sudoku[i][j] = 0; //Backtrack
        }
    }
    return false;
}

int main(){
    int sudoku[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,3,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    };
    solve_sudoku(sudoku,9,0,0);
}