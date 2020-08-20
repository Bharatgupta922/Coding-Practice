#include <iostream>
using namespace std;
int lis(int *a, int n)
{
    int dp[n + 1];
    dp[0] = 1;
    int max = 1;
    for (int i = 1; i < n; ++i)
    {
        int j = 0, t = 1;
        while (j < i)
        {
            if (a[j] < a[i] && t <= dp[j])
            {
                ++t;
            }
            ++j;
        }
        dp[i] = t;
        if (max < dp[i])
            max = dp[i];
    }
    return max;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << lis(a, n);
    }
}