#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    for (int row = 0; row < i; ++row)
    {
        if (board[row][j] == 1)
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
bool solveNQueen(int board[][10], int i, int n, vector<int> &ans)
{

    if (i == n)
    {
        //print the board
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                if (board[x][y] == 1)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        for (int x = 0; x < n; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                if (board[x][y] == 1)
                {
                    ans.push_back(y + 1);
                    board[x][y] = 0;
                }
            }
        }
        return true;
    }
    for (int j = 0; j < n; ++j)
    {
        if (isSafe(board, i, j, n) == true)
        {
            board[i][j] = 1;
            bool success = solveNQueen(board, i + 1, n , ans);
            if (success == true)
                return true;
            board[i][j] = 0;
        }
    }
    return false;
}
int main()
{

    int n;
    cin >> n;
    vector<int> ans;
    int board[10][10] = {0};
    solveNQueen(board, 0, n, ans);
    cout<<endl;
    for(auto x : ans){
        cout<<x<<" ";
    }
    return 0;
}       