#include <iostream>
#include <climits>
using namespace std;
int recursion(int coins[], int n, int amt)
{
    if (amt == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return INT_MAX - 1;
    }
    if (n == 1)
    {
        if (amt % coins[0] == 0)
        {
            return amt / coins[0];
        }
        else
        {
            return INT_MAX - 1;
        }
    }
    if (coins[n - 1] <= amt)
    {
        return min(recursion(coins, n - 1, amt), 1 + recursion(coins, n, amt - coins[n - 1]));
    }
    else
    {
        return recursion(coins, n - 1, amt);
    }
}
int memoization(int coins[], int n, int amt, int **dp)
{
    if (amt == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return INT_MAX - 1;
    }
    if (n == 1)
    {
        if (amt % coins[0] == 0)
        {
            return amt / coins[0];
        }
        else
        {
            return INT_MAX - 1;
        }
    }
    if (dp[n][amt] != -1)
    {
        return dp[n][amt];
    }
    if (coins[n - 1] <= amt)
    {
        return dp[n][amt] = min(memoization(coins, n - 1, amt, dp), 1 + memoization(coins, n, amt - coins[n - 1], dp));
    }
    else
    {
        return dp[n][amt] = memoization(coins, n - 1, amt, dp);
    }
}
int tabulation(int coins[], int n, int amt)
{
    int dp[n + 1][amt + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < amt + 1; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            if (i == 1)
            {
                if (j % coins[0] == 0) // coins[0] first element or only element of the array 
                {
                    dp[i][j] = j / coins[0];
                }
                else
                {
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
    }
    for (int i = 2; i < n + 1; ++i)
    {
        for (int j = 1; j < amt + 1; ++j)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amt];
}
void solve(int coins[], int n, int amt)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i] = new int[amt + 1];
    }
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < amt + 1; ++j)
        {
            dp[i][j] = -1;
        }
    }
    int ans = tabulation(coins, n, amt);

    ans < (INT_MAX - 1) ? cout << ans << endl : cout << "-1" << endl;
    // cout << memoization(coins, n, amt, dp) << endl;
    // cout << recursion(coins, n, amt) << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int amt;
        cin >> amt;
        int n;
        cin >> n;
        int coins[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> coins[i];
        }
        solve(coins, n, amt);
    }
    return 0;
}