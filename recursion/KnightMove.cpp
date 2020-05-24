#include <iostream>
#include <iomanip>
using namespace std;
const int D = 8;
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
bool canPlace(int board[D][D], int n, int r, int c)
{
    return r >= 0 && r < n &&
           c >= 0 && c < n &&
           board[r][c] == 0;
}
bool solveKnigtMove(int board[D][D], int n, int move_no, int curRow, int curCol)
{
    //base case
    if (move_no == n * n)
        return true;

    static int rowDir[] = {2, 1, -1, -2, -2, -1, 1, 2};
    static int colDir[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int curDir = 0; curDir < 8; ++curDir)
    {
        int nextRow = curRow + rowDir[curDir];
        int nextCol = curCol + colDir[curDir];
        if (canPlace(board, n, nextRow, nextCol))
        {
            //place the knight ;
            board[nextRow][nextCol] = move_no + 1;
            bool isSuccesfull = solveKnigtMove(board, n, move_no + 1, nextRow, nextCol);
            if (isSuccesfull == true)
                return true;
            board[nextRow][nextCol] = 0; // erase the knight  //backtracking step
        }
    }
    return false;
}
int main()
{
    int board[D][D] = {0};
    int n;
    cout << "input the dimensions" << endl;
    cin >> n;

    board[0][0] = 1;
    bool ans = solveKnigtMove(board, n, 1, 0, 0);
    if (ans == true)
    {
        printBoard(board, n);
    }
    else
    {
        cout << "sorry ! cant visit your board";
    }
    return 0;
}