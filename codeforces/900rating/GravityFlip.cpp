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
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    bool check;
    while (1)
    {
        check = true;
        for (int i = 0; i < n - 1; ++i)
        {
            if (a[i] > a[i + 1])
            {
                int minus = a[i] - a[i + 1];
                a[i + 1] += minus;
                a[i] -= minus;
                check = false;
            }
        }
        if (check)
            break;
    }
    for (auto x : a)
    {
        cout << x << " ";
    }

    return 0;
}