#include <bits/stdc++.h>
using namespace std;

int knapsackUtil(int price[], int wt[], int W, int n, int **dp)
{
    if (n == 0 || W == 0)
        return 0;
    if (dp[W][n] != -1)
        return dp[W][n];
    if (wt[n - 1] <= W)
    {
        return dp[W][n] = max(price[n - 1] + knapsackUtil(price, wt, W - wt[n - 1], n - 1, dp),
                              knapsackUtil(price, wt, W, n - 1, dp));
    }
    else
        return dp[W][n] = knapsackUtil(price, wt, W, n - 1, dp);
}
int knapsack(int price[], int wt[], int W, int n)
{
    int **dp = new int *[W + 1];
    for (int i = 0; i < W + 1; ++i)
    {
        dp[i] = new int[n + 1];
    }
    for (int i = 0; i < W + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            dp[i][j] = -1;
        }
    }
    return knapsackUtil(price, wt, W, n, dp);
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int W;
        cin >> W;
        int price[n], wt[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> price[i];
        }
        for (int j = 0; j < n; ++j)
        {
            cin >> wt[j];
        }
        cout << knapsack(price, wt, W, n) << endl;
    }
    return 0;
}