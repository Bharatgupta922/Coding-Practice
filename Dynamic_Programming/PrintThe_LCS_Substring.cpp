#include <iostream>
#include <algorithm>
using namespace std;
int **LCS(string x, string y, int m, int n, int **dp)
{
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
    return dp;
}
string printLCS(string x, string y, int m, int n, int **dp)
{
    string op = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            op.push_back(x[i - 1]);
            --i;
            --j;
        }
        else
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                --j;
            }
            else
            {
                --i;
            }
        }
    }
    return op;
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
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    dp = LCS(x, y, m, n, dp);
    string output = printLCS(x, y, m, n, dp);
    reverse(output.begin(), output.end());
    cout << output << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        string x, y;
        cin >> x >> y;
        solve(x, y, m, n);
    }
    return 0;
}