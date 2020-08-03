#include <bits/stdc++.h>
using namespace std;

//recursive approach
int ways(int n)
{

    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    int ans = ways(n - 1) + ways(n - 2) + ways(n - 3);
    return ans;
}

//top down approach
int waysTD(int n, int *dp)
{
    if (n == 0)
    {
        dp[0] = 1;
        return dp[0];
    }
    if (n < 0)
    {
        return 0;
    }
    dp[n] = waysTD(n - 1, dp) + waysTD(n - 2, dp) + waysTD(n - 3, dp);
    return dp[n];
}

// bottom up approach
int waysBU(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
}

//recursive approach
int ways2(int n, int k)
{

    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    int ans = 0;
    for (int i = 1; i <= k; ++i)
        ans += ways2(n - i, k);
    return ans;
}

//top down approach
int waysTD2(int n, int *dp, int k)
{
    if (n == 0)
    {
        dp[0] = 1;
        return dp[0];
    }
    if (n < 0)
    {
        return 0;
    }
    int temp = 0;
    for (int i = 1; i <= k; ++i)
        temp += waysTD2(n - i, dp, k);
    dp[n] = temp;
    return dp[n];
}

// bottom up approach
int waysBU2(int n, int k)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int temp = 0;
    for (int i = 3; i <= n; ++i)
    {
        temp = 0;
        for (int j = 1; j <= k; ++j)
        {
            temp += dp[i - j];
        }

        dp[i] = temp;
    }
    return dp[n];
}

int main()
{

    // n is number of stairs
    // k is maximum jump you can make
    //you need to get maximum ways to get to the top of stairs
    int dp[100];
    memset(dp, -1, sizeof(dp));
    int n = 4;
    int k = 3;
    cout << ways(n) << endl;
    cout << waysTD(n, dp) << endl;
    cout << waysBU(n) << endl;
    // customised functions
    cout << ways2(n, k) << endl;
    cout << waysTD2(n, dp, k) << endl;
    cout << waysBU2(n, k) << endl;

    return 0;
}