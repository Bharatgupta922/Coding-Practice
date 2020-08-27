// Given two strings str1 and str2, find the length of the smallest string which has both,
// str1 and str2 as its sub-sequences.

// Input:
// 2
// abcd xycd
// efgh jghi
// Output:
// 6
// 6

#include <iostream>
using namespace std;
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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
void solve(string x, string y, int m, int n)
{
    int lcs = LCS(x, y, m, n);
    int output = m + n - lcs;
    cout << output << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        solve(x, y, x.length(), y.length());
    }
    return 0;
}