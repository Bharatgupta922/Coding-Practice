#include <bits/stdc++.h>

using namespace std;

void printBoard(int board[10][10], int n)
{
    cout << "[";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 1)
            {
                cout << j + 1 << " ";
            }
        }
    }
    cout << "] ";
}

bool isSafe(int board[10][10], int i, int j, int n)
{
    for (int x = 0; x < n; ++x)
    {
        if (board[x][j] == 1)
        {
            return false;
        }
    }
    for (int x = i, y = j; x >= 0 && y >= 0; --x, --y)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }
    for (int x = i, y = j; x >= 0 && y < n; --x, ++y)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
    }
    return true;
}

bool nqueen(int board[10][10], int i, int n)
{
    if (i == n)
    {
        printBoard(board, n);
        return true;
    }
    bool res = false;
    for (int j = 0; j < n; ++j)
    {
        if (isSafe(board, i, j, n))
        {
            board[i][j] = 1;
            res = nqueen(board, i + 1, n) || res;
            board[i][j] = 0;
        }
    }
    return res;
}

void solve(int n)
{
    int board[10][10];
    memset(board, 0, sizeof(board));
    if (!nqueen(board, 0, n))
    {
        cout << "-1";
    }
    cout << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
}