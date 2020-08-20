#include <bits/stdc++.h>
using namespace std;
int minDel(int *a, int n)
{
    int dp[n + 1];
    dp[0] = 1;
    int lis = 1;
    for (int i = 0; i < n; ++i)
    {
        int j = 0, t = 1;
        while (j < i)
        {
            if (a[j] < a[i] && t <= dp[j])
                ++t;
            ++j;
        }
        dp[i] = t;
        lis = max(lis, t);
    }
    return n - lis;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        cout << minDel(a, n) << endl;
    }

    return 0;
}