#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const int D = 10;
void printBoard(int board[D][D], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << board[i][j] << "  ";
        }
        cout << endl;
    }
}
bool canPlace(int board[D][D], int n, int row, int col, int curNum)
{
    if (board[row][col] != 0)
    {
        return false;
    }
    // check row & col
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == curNum)
            return false;
        if (board[row][i] == curNum)
            return false;
    }

    // check in small box

    for (int i = (int)sqrt(n) * (int)(row / sqrt(n)); i < (int)sqrt(n) * (int)(row / sqrt(n)) + (int)sqrt(n); ++i)
    {
        for (int j = (int)sqrt(n) * (int)(col / sqrt(n)); j < (int)sqrt(n) * (int)(col / sqrt(n)) + (int)sqrt(n); ++j)
        {
            if (board[i][j] == curNum)
            {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int board[D][D], int n, int row, int col)
{
    if (row == n)
    {
        // completed the [0,n) rows
        return true;
    }
    if (col == n)
    {
        // start with new row
        return solveSudoku(board, n, row + 1, 0);
    }
    if (board[row][col] != 0)
    {
        return solveSudoku(board, n, row, col + 1);
    }
    for (int curNum = 1; curNum <= n; ++curNum)
    {
        if (canPlace(board, n, row, col, curNum) == true)
        {
            board[row][col] = curNum;
            bool success = solveSudoku(board, n, row, col + 1);
            if (success == true)
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    // int board[D][D] = {
    //     {5, 3, 0, 0, 7, 0, 0, 0, 0},
    //     {6, 0, 0, 1, 9, 5, 0, 0, 0},
    //     {0, 9, 8, 0, 0, 0, 0, 6, 0},
    //     {8, 0, 0, 0, 6, 0, 0, 0, 3},
    //     {4, 0, 0, 8, 0, 3, 0, 0, 1},
    //     {7, 0, 0, 0, 2, 0, 0, 0, 6},
    //     {0, 6, 0, 0, 0, 0, 2, 8, 0},
    //     {0, 0, 0, 4, 1, 9, 0, 0, 5},
    //     {0, 0, 0, 0, 8, 0, 0, 7, 9}
    //     };

    int n;
    cin >> n;
    int board[D][D];
    for(int i =0 ;i <n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            cin>>board[i][j];
        }
    }
    bool success = solveSudoku(board, n, 0, 0);
    if (success == true)
    {
        printBoard(board, n);
    }
    else
    {
        cout << "sorry !";
    }
}