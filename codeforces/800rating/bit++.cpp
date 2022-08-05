#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int x = 0;
    while (t--)
    {
        string ip;
        cin >> ip;
        if (ip == "X++" || ip == "++X")
            x++;
        else
            --x;
    }
    cout << x;
    return 0;
}