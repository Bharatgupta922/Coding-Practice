#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int dp[1001][1001];
int palindromeDP[1001][1001];
bool palindrome(string s, int i, int j)
{
    bool result = 1;
    while (i <= j)
    {
        if (s[i++] != s[j--])
        {
            result = 0;
            break;
        }
    }
    return palindromeDP[i][j] = result;
}
int recursion(string s, int i, int j)
{
    if (i > j || i == j)
    {
        return 0;
    }
    if (palindrome(s, i, j) == true)
    {
        return 0;
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; ++k)
    {
        int tempans = 1 + recursion(s, i, k) + recursion(s, k + 1, j);
        mn = min(tempans, mn);
    }
    return mn;
}
int memoization(string s, int i, int j)
{
    if (i > j || i == j)
    {
        return 0;
    }
    if (palindrome(s, i, j) == true)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; ++k)
    {
        int tempans = 1 + memoization(s, i, k) + memoization(s, k + 1, j);
        mn = min(tempans, mn);
    }
    return dp[i][j] = mn;
}
int memoizationOptimised(string s, int i, int j)
{
    if (i > j || i == j)
    {
        return 0;
    }
    if (palindromeDP[i][j] != -1)
    {
        if (palindromeDP[i][j] == 1)
        {
            return palindromeDP[i][j];
        }
    }
    if (palindrome(s, i, j) == 1)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; ++k)
    {
        int left, right;
        // dp[i][k] != -1 ? left = dp[i][k] : dp[i][k] = left = memoizationOptimised(s, i, k);
        // dp[k + 1][j] != -1 ? right = dp[k + 1][j] : dp[k + 1][j] = right = memoizationOptimised(s, k + 1, j);
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else {
            left = memoizationOptimised(s,i,k);
            dp[i][k] = left;
        }
        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else {
            right = memoizationOptimised(s,k+1,j);
            dp[k+1][j] = right;
        }
        int tempans = 1 + left + right;
        mn = min(tempans, mn);
    }
    return dp[i][j] = mn;
}

void solve(string s)
{
    memset(dp, -1, sizeof(dp));
    memset(palindromeDP, -1, sizeof(palindromeDP));
    int output;
    // output = recursion(s, 0, s.length() - 1);
    output = memoizationOptimised(s, 0, s.length() - 1);
    cout << output << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        solve(str);
    }
    return 0;
}
