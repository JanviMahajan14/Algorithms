#include<iostream>
using namespace std;

bool isplacedsafe(int board[][10],int n, int i, int j){
    // Checking along the column
    int x = i-1;
    while(x>=0){
        if(board[x][j]==1){
            return false;
        }
        x--;
    }

    //Checking along the right diagonal
    x = i-1;
    int y = j+1;
    while(x>=0 && y<=(n-1)){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    // Checking along the left diagonal
    x = i-1;
    y = j-1;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    return true;
}

bool solve_n_queen(int board[][10], int n, int i){
    if(i==n){
        // print the board
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){
                    cout << "Q ";
                }
                else{
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return false; //Even we have solved we will tell the fn to look for other possibilty
    }
    
    for(int j=0; j<n; j++){
        if(isplacedsafe(board,n,i,j)){
            board[i][j]=1;
            bool isRakhPaye = solve_n_queen(board,n,i+1);

            if(isRakhPaye){
                return true;
            }
            
             board[i][j]=0; //Backtrack : correct our asumption

        }
    }
    return false;

}

int main(){
    int n;
    cin >> n;
    int board[n][10]={0};
    //Placing the queens row wise
    solve_n_queen(board,n,0);
}