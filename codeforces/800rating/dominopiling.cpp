#include <bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, y;
    cin >> x >> y;
    int res = (x * y) / 2;
    cout << res;

    return 0;
}