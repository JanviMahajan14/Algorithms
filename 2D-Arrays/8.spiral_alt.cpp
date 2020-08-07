#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int a[r][c];

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> a[i][j];
            }
        }

        int row_start = 0;
        int row_end = r - 1;
        int col_start = 0;
        int col_end = c - 1;

        while (row_start <= row_end && col_start <= col_end)
        {
            if ((row_start == row_end) && (row_start == col_start) && (row_start == col_end))
            {
                cout << a[row_start][col_start] << " ";
            }

            for (int j = col_start, i = row_start; j < col_end; j++)
            {
                cout << a[i][j] << " ";
            }

            for (int i = row_start, j = col_end; i < row_end; i++)
            {
                cout << a[i][j] << " ";
            }

            for (int j = col_end, i = row_end; j > col_start; j--)
            {
                cout << a[i][j] << " ";
                if (row_end == row_start)
                    break;
            }

            for (int i = row_end, j = col_start; i > row_start; i--)
            {
                cout << a[i][j] << " ";
                if (col_end == col_start)
                    break;
            }

            row_start++;
            col_start++;
            row_end--;
            col_end--;
        }

        cout
            << endl;
    }
}