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
    int output = m + n - 2 * lcs;
    cout << output << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        string x, y;
        cin >> m >> n >> x >> y;
        solve(x, y, m, n);
    }

    return 0;
}