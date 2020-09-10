#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

// i,j -->coordinates of starting point
// ch -->char which is to be replaced
// color ---> with which we have to replace

void flood_fill(int mat[][100], int i, int j, int ch, int color, int row, int col)
{
    if (i < 0 || j < 0 || i > row || j > col)
    {
        return;
    }

    if (mat[i][j] != ch)
    {
        return;
    }

    mat[i][j] = ch;

    for (int k = 0; k < 4; k++)
    {
        flood_fill(mat, i + dx[k], j + dy[k], ch, color, row, col);
    }
}