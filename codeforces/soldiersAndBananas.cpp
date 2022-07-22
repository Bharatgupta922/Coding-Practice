#include <bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b, c;
    cin >> a >> b >> c;
    int ans = (a * ((c * (c + 1)) / 2) - b);
    if (ans <= 0)
        cout << 0;
    else
        cout << ans;
    return 0;
}