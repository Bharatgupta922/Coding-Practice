#include <bits/stdc++.h>
using namespace std;
int Solve(int *a, int n)
{
    int dp[n + 1];
    for (int i = 0; i < n; ++i)
        dp[i] = a[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }
    return *max_element(dp, dp + n);
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
        cout << Solve(a, n);
    }
    return 0;
}