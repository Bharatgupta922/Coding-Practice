#include <iostream>
#include <algorithm>
using namespace std;
int recursion(string x, string y, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (x[m - 1] == y[n - 1])
    {
        return 1 + recursion(x, y, m - 1, n - 1);
    }
    else
    {
        return max(recursion(x, y, m - 1, n), recursion(x, y, m, n - 1));
    }
}
int memoization(string x, string y, int m, int n, int **dp)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    if (x[m - 1] == y[n - 1])
    {
        return dp[m][n] = 1 + memoization(x, y, m - 1, n - 1, dp);
    }
    else
    {
        return dp[m][n] = max(memoization(x, y, m - 1, n, dp), memoization(x, y, m, n - 1, dp));
    }
}
int LCS(string x, string y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
}
void solve(string x, string y, int m, int n)
{

    int **dp = new int *[m + 1];
    for (int i = 0; i < m + 1; ++i)
    {
        dp[i] = new int[n + 1];
    }
    for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            dp[i][j] = -1;
        }
    }
    int lcs;
    // lcs = memoization(x, y, m, n, dp) ;
    // lcs =  recursion(x, y, m, n) ;
    lcs = LCS(x, y, m, n); // tabulation
    int output = m - lcs;
    cout << output << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;
        string temp = x;
        reverse(temp.begin(), temp.end());
        string y = temp;
        solve(x, y, x.length(), y.length());
    }
    return 0;
}