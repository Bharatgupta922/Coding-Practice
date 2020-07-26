#include <bits/stdc++.h>
using namespace std;
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
    }
    return 0;
}