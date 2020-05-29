#include<iostream>
using namespace std;

bool rat_in_maze(char in[][10], int out[][10], int i, int j, int m, int n){

    // If path is blocked
    if(in[i][j] == 'X'){
        return false;
    }
    // If running outside the grid
    if(i==m || j==n){
        return false;
    }
    // if dest is achieved
    if(i== (m-1) && j == (n-1)){
        out[i][j]=1;
        for(int a=0; a<m; a++){
            for(int b=0; b<n; b++){
                cout << out[a][b] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    out[i][j]=1;
    bool right = rat_in_maze(in,out,i,j+1,m,n);
    bool down = rat_in_maze(in,out,i+1,j,m,n);

    // if getting false from both the paths
    if(right == false && down == false){
        out[i][j]=0;
        return false;
    }
}

int main(){
    int m=4,n=4;
    char in[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };
    int out[10][10] = {0};
    bool result = rat_in_maze(in,out,0,0,m,n);
}