#include <iostream>
using namespace std;
//simple recursion
bool SubsetSum(int arr[], int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (arr[n - 1] <= sum)
    {
        return SubsetSum(arr, sum - arr[n - 1], n - 1) || SubsetSum(arr, sum, n - 1);
    }
    else
        return SubsetSum(arr, sum, n - 1);
}
    
//tabulation

bool tabulation(int arr[], int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
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
        // cout<<SubsetSum(arr,sum , n)<<endl; ////simple recursion solution
        cout << tabulation(arr, sum, n);
    }

    return 0;
}