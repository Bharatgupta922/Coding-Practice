#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int static dp[1001][1001];
int recursion(int arr[], int i, int j)
{
    if (i > j || i == j)
    {
        return 0;
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; ++k)
    {
        int tempans = recursion(arr, i, k) + recursion(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, tempans);
    }
    return mn;
}
int memoization(int arr[], int i, int j)
{
    if (i > j || i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; ++k)
    {
        int tempans = memoization(arr, i, k) + memoization(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, tempans);
    }
    return dp[i][j] = mn;
}
void solve(int arr[], int n)
{
    memset(dp, -1, sizeof(dp));

    int output;
    output = memoization(arr, 1, n - 1);
    // output = recursion(arr, 1, n - 1);
    cout << output << endl;
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
        solve(arr, n);
    }

    return 0;
}