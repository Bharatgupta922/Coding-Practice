// Partition a set into two subsets such that the difference of subset sums is minimum
// Given a set of integers, the task is to divide it into two sets S1 and S2
//  such that the absolute difference between their sums is minimum.

// If there is a set S with n elements, then if we assume Subset1 has m elements,
// Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

// Example:

// Input:  arr[] = {1, 6, 11, 5}
// Output: 1
// Explanation:
// Subset1 = {1, 5, 6}, sum of Subset1 = 12
// Subset2 = {11}, sum of Subset2 = 11

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int MinimumSum(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; ++i)
    {
        range += arr[i];
    }
    bool dp[n + 1][range + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < range + 1; ++j)
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
        for (int j = 1; j < range + 1; ++j)
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
    vector<int> valid;
    for (int i = 0; i <= range / 2; ++i)
    {
        if (dp[n][i] == true)
        {
            valid.push_back(i);
        }
    }
    int result = INT_MAX;
    for (auto x : valid)
    {
        result = min(result, range - 2 * x);
    }
    return result;
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
        cout << MinimumSum(arr, n) << endl;
    }
    return 0;
}