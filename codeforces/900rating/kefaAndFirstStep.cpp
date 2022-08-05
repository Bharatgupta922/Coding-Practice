#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(x, n) for (int x = 0; x < n; ++x)
int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[n];

    f(i, n) cin >> a[i];
    int count = 0, maxCount = 0;
    f(i, n - 1)
    {
        if (a[i] <= a[i + 1])
            count++;
        else
            count = 0;
        maxCount = max(count, maxCount);
    }
    cout << maxCount + 1;
    return 0;
}