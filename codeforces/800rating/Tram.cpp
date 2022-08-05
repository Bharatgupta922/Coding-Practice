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
    int cap = 0;
    int res = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cap -= a;
        cap += b;
        res = max(res, cap);
    }
    cout << res;

    return 0;
}