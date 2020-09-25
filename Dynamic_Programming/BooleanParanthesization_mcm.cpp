// Given a boolean expression with following symbols.

// Symbols
//     'T' ---> true
//     'F' ---> false

// And following operators filled between symbols

// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR

// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// For Example:
// The expression is "T | T & F ^ T", it evaluates true
// in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T)
// and (T|((T&F)^T)).

// Return No_of_ways Mod 1003.

// Input:
// First line contains the test cases T.  1<=T<=500
// Each test case have two lines
// First is length of string N.  1<=N<=100
// Second line is string S (boolean expression).
// Output:
// No of ways Mod 1003.

// Example:
// Input:
// 2
// 7
// T|T&F^T
// 5
// T^F|F

// Output:
// 4
// 2

#include <iostream>
#include <unordered_map>
#define mod 1003
#define ll long long
using namespace std;
unordered_map<string, ll> mp;
int dp[101][101][5];
ll recursive(string str, int i, int j, bool isCheck)
{
    if (i > j)
    {
        return false;
    }
    if (i == j)
    {

        if (isCheck == true)
        {
            return (str[i] == 'T');
        }

        else
        {
            return (str[i] == 'F');
        }
    }

    ll ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = recursive(str, i, k - 1, true);
        int rt = recursive(str, k + 1, j, true);
        int lf = recursive(str, i, k - 1, false);
        int rf = recursive(str, k + 1, j, false);

        if (str[k] == '&')
        {
            if (isCheck == true)
            {
                ans = (ans + (lt * rt) % mod) % mod;
            }

            else
            {
                ans = (ans + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
        else if (str[k] == '|')
        {
            if (isCheck == true)
            {
                ans = (ans + (lt * rf) % mod + (lf * rt) % mod + (lt * rt) % mod) % mod;
            }

            else
            {
                ans = (ans + (lf * rf) % mod) % mod;
            }
        }
        else if (str[k] == '^')
        {
            if (isCheck == true)
            {
                ans = (ans + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }

            else
            {
                ans = (ans + (lt * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
    }

    return ans % mod;
}

ll memoization(string str, int i, int j, bool isCheck)
{
    if (i > j)
    {
        return false;
    }
    if (i == j)
    {

        if (isCheck == true)
        {
            return (str[i] == 'T');
        }

        else
        {
            return (str[i] == 'F');
        }
    }

    if (dp[i][j][isCheck] != -1)
    {
        return dp[i][j][isCheck];
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt, rt, lf, rf;
        if (dp[i][k - 1][true] != -1)
        {
            lt = dp[i][k - 1][true];
        }
        else
        {
            lt = memoization(str, i, k - 1, true);
            dp[i][k - 1][true] = lt;
        }
        if (dp[k + 1][j][true] != -1)
        {
            rt = dp[k + 1][j][true];
        }
        else
        {
            rt = memoization(str, k + 1, j, true);
            dp[k + 1][j][true] = rt;
        }
        if (dp[i][k - 1][false] != -1)
        {
            lf = dp[i][k - 1][false];
        }
        else
        {
            lf = memoization(str, i, k - 1, false);
            dp[i][k - 1][false] = lf;
        }
        if (dp[k + 1][j][false] != -1)
        {
            rf = dp[k + 1][j][false];
        }
        else
        {
            rf = memoization(str, k + 1, j, false);
            dp[k + 1][j][false] = rf;
        }

        if (str[k] == '&')
        {
            if (isCheck == true)
            {
                ans = (ans + (lt * rt) % mod) % mod;
            }

            else
            {
                ans = (ans + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
        else if (str[k] == '|')
        {
            if (isCheck == true)
            {
                ans = (ans + (lt * rf) % mod + (lf * rt) % mod + (lt * rt) % mod) % mod;
            }

            else
            {
                ans = (ans + (lf * rf) % mod) % mod;
            }
        }
        else if (str[k] == '^')
        {
            if (isCheck == true)
            {
                ans = (ans + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }

            else
            {
                ans = (ans + (lt * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
    }

    return dp[i][j][isCheck] = ans % mod;
}

void solve(string s, int n)
{

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            for (int k = 0; k <= 2; ++k)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    ll output;
    // output = recursive(s, 0, n - 1, true);
    output = memoization(s, 0, n - 1, true);
    cout << output << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        mp.clear();
        solve(s, n);
    }

    return 0;
}
