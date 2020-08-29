// Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

// Examples:

// Input: arr[] = {1, 2, 3, 3}, X = 6
// Output: 3
// All the possible subsets are {1, 2, 3},
// {1, 2, 3} and {3, 3}

// Input: arr[] = {1, 1, 1, 1}, X = 1
// Output: 4

#include <iostream>
using namespace std;
int countSubset(int arr[], int sum, int n)
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
        return countSubset(arr, sum - arr[n - 1], n - 1) + countSubset(arr, sum, n - 1);
    }
    else
    {
        return countSubset(arr, sum, n - 1);
    }
}
int tabulation(int arr[], int sum, int n)
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
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
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
        // cout << countSubset(arr, sum, n) << endl; ////recursive solution
        cout << tabulation(arr, sum, n) << endl;
    }
    return 0;
}