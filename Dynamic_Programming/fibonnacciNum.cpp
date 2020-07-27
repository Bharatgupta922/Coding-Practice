#include <bits/stdc++.h>
using namespace std;
// top down approach  -- recursive approach
int fibDP(int n, int *dp)
{
    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = fibDP(n - 1, dp) + fibDP(n - 2, dp);
        return dp[n];
    }
}

// bottom up approach -- iterative approach
int fib(int n)
{
    int *dp = new int[n];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
int fibOpt(int n)
{
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dp[100];
        memset(dp, -1, sizeof(dp));
        cout << fibDP(n, dp) << endl;
        cout << fib(n) << endl;
        cout << fibOpt(n);
    }
    return 0;
}