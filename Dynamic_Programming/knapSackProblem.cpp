#include <bits/stdc++.h>
using namespace std;
    
int knapsack(int wts[], int prices[], int n, int w)
{

    if (n == 0 || w == 0)
    {
        return 0;
    }

    int incl = 0, excl = 0;
    if (wts[n - 1] <= w)
    {
        incl = prices[n - 1] + knapsack(wts, prices, n - 1, w - wts[n - 1]);
    }
    excl = 0 + knapsack(wts, prices, n - 1, w);

    return max(incl, excl);
}

//bottom up approach
int knapsackDP(int wts[], int prices[], int n, int W)
{

    int dp[100][100];
    for (int i = 0; i <= n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
                continue;
            }
            int inc = 0, excl = 0;
            if (wts[i - 1] <= w)
            {
                inc = prices[i - 1] + dp[i - 1][w - wts[i - 1]];
            }
            excl = 0 + dp[i - 1][w];
            dp[i][w] = max(inc, excl);
        }
    }
    return dp[n][W];
}
int main()
{
    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};
    int n = 4;
    int Bagweight = 11;
    // int maxProfit = knapsack(wts, prices, n, Bagweight);
    // cout << maxProfit << endl;

    int maxProfit = knapsackDP(wts, prices, n, Bagweight);
    cout << maxProfit;
    return 0;
}