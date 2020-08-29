#include <iostream>
using namespace std;
int recursion(int arr[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (arr[n - 1] <= sum)
    {
        return recursion(arr, n - 1, sum) + recursion(arr, n, sum - arr[n - 1]);
    }
    else
        return recursion(arr, n - 1, sum);
}
int memoization(int arr[], int n, int sum, int **dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (arr[n - 1] <= sum)
    {
        return dp[n][sum] = memoization(arr, n - 1, sum, dp) + memoization(arr, n, sum - arr[n - 1], dp);
    }
    else
        return dp[n][sum] = memoization(arr, n - 1, sum, dp);
}
int tabulation(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
void solve(int arr[], int n, int sum)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i] = new int[sum + 1];
    }
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
        {
            dp[i][j] = -1;
        }
    }
    cout << tabulation(arr, n, sum) << endl;
    cout << memoization(arr, n, sum, dp) << endl;
    cout << recursion(arr, n, sum) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum;
        cin >> sum;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        solve(arr, n, sum);
    }
    return 0;
}