#include <iostream>
#include <climits>
using namespace std;
int recursion(string x, string y, int m, int n, int count)
{
    if (m == 0 || n == 0)
    {
        return count;
    }
    if (x[m - 1] == y[n - 1])
    {
        return recursion(x, y, m - 1, n - 1, count + 1);
    }
    else
    {
        return count = max(count, max(recursion(x, y, m - 1, n, 0), recursion(x, y, m, n - 1, 0)));
    }
}
int tabulation(string x, string y, int m, int n)
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
    int count = 0;
    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                count = max(count, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return count;
}
void solve(string x, string y, int m, int n)
{
    int count = 0;
    cout << recursion(x, y, m, n, count) << endl;
    cout << tabulation(x, y, m, n) << endl;
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