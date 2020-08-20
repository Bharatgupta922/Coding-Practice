#include <iostream>
using namespace std;
int solve(int price[], int wt[], int W, int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < W + 1; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < W + 1; ++j)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int W;
        cin >> W;
        int n = W;
        int wt[n], price[n];
        for (int i = 0; i < W; ++i)
        {
            wt[i] = i + 1;
            cin >> price[i];
        }

        cout << solve(price, wt, W, n) << endl;
    }

    return 0;
}