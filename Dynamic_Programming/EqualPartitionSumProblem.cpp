// Given a set of numbers, check whether it can be partitioned into two subsets
//such that the sum of elements in both subsets is same or not.

// Input:
// 2
// 4
// 1 5 11 5
// 3
// 1 3 5

// Output:
// YES
// NO

#include <iostream>
using namespace std;
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
bool tabulationSubsetSum(int arr[], int sum, int n)
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
bool EqualPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    // return SubsetSum(arr , sum / 2 , n); //// recursive solution
    return tabulationSubsetSum(arr, sum / 2, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        bool success = EqualPartition(arr, n);
        success ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}