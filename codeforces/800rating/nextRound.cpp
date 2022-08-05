#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i != k - 1 && a[i] != 0 && a[i] >= a[k - 1])
        {
            count++;
        }
    }
    if (a[k - 1] != 0)
        count++;
    cout << count;
    return 0;
}