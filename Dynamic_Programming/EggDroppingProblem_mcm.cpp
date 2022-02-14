#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int static dp[11][51];
int memoization(int e, int f)
{
    if (e == 0 || e == 1 || f == 0 || f == 1)
    {
        return f;
    }
    if (dp[e][f] != -1)
    {
        return dp[e][f];
    }
    int mn = INT_MAX;
    for (int k = 1; k <= f; ++k)
    {
        int do_Break, not_Break;
        if (dp[e - 1][k - 1] != -1)
        {
            do_Break = dp[e - 1][k - 1];
        }
        else
        {
            do_Break = memoization(e - 1, k - 1);
        }
        if (dp[e][f - k] != -1)
        {
            not_Break = dp[e][f - k];
        }
        else
        {
            not_Break = memoization(e, f - k);
        }

        int temp = 1 + max(do_Break, not_Break);
        mn = min(mn, temp);
    }
    return dp[e][f] = mn;
}

// int recursive(int e, int f)
// {

//     if (e == 0 || e == 1 || f == 0 || f == 1)
//     {
//         return f;
//     }
//     int mn = INT_MAX;
//     for (int k = 1; k <= f; ++k)
//     {
//         int temp = 1 + max(recursive(e - 1, k - 1), recursive(e, f - k));
//         mn = min(mn, temp);
//     }
//     return mn;
// }

void solve(int e, int f)
{

    int output;
    // output = recursive(e, f);
    memset(dp, -1, sizeof(dp));
    // cout << recursive << endl;
    cout << memoization(e, f) << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int e, f;
        // e --> eggs
        // f --> floors
        cin >> e >> f;
        solve(e, f);
    }

    return 0;
}