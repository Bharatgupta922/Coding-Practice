#include <iostream>
using namespace std;
int recursion(int val[], int wt[], int W, int n)
{
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= W)
        return max(val[n - 1] + recursion(val, wt, W - wt[n - 1], n), recursion(val, wt, W, n - 1));
    else
        return recursion(val, wt, W, n - 1);
}
int tabulation(int val[] , int wt[] , int W , int n){
    int dp[n+1][W+1];
    for(int i = 0 ; i < n + 1 ; ++i){
        for(int j = 0 ; j < W + 1 ; ++j){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i < n + 1 ; ++i){
        for(int j = 1 ; j < W + 1 ; ++j){
            if(wt[i - 1] <= j){
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i-1]] , dp[i - 1][j]);
            }
            else dp[i][j] = dp[i - 1][j] ;
        }
    }
   return  dp[n][W];
}
int memoization(int price[], int wt[], int W, int n, int **dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(price[n - 1] + memoization(price, wt, W - wt[n - 1], n, dp), memoization(price, wt, W, n - 1, dp));
    }
    else
    {
        return dp[n][W] = memoization(price, wt, W, n - 1, dp);
    }
}
void solve(int val[], int wt[], int W, int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i] = new int[W + 1];
    }

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < W + 1; ++j)
        {
            dp[i][j] = -1;
        }
    }
   cout<< memoization(val, wt, W, n, dp)<<endl;
    cout << recursion(val, wt, W, n) << endl;
    cout<<tabulation(val , wt , W , n )<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int W;
        cin >> W;
        int val[n], wt[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> wt[i];
        }
        solve(val, wt, W, n);
    }
    return 0;
}