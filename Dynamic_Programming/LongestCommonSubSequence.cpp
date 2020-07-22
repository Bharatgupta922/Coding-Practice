#include <iostream>
using namespace std;
int lcs(string x, string y, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
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
        int m, n;
        cin >> m >> n;
        string x, y;
        cin >> x >> y;
        cout << lcs(x, y, m, n) << endl;
    }
    //code
    return 0;
}