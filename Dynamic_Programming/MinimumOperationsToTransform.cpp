#include <bits/stdc++.h>
using namespace std;
//you have two strings x ,y
// you have to change x into y
// there are three types of operations that you can perform on x to transform it into y
// that are : delete ,replace and insert
// you have to find the minimum number of operations could perform to do the same task
int min(int a, int b, int c)
{
    return a < b ? a < c ? a : c : b < c ? b : c;
}
int MaxOp(string x, string y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        cout << MaxOp(x, y, x.length(), y.length()) << endl;
    }
    return 0;
}