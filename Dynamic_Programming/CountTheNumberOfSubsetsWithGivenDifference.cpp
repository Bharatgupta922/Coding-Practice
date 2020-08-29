#include <iostream>
using namespace std;
int countSubsets(int arr[], int n, int sum)
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
void solve(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    int sum1 = (sum - diff) / 2;
    int count = countSubsets(arr, n, sum1);
    cout << count << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int diff;
        cin >> diff;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        solve(arr, n, diff);
    }
    return 0;
}