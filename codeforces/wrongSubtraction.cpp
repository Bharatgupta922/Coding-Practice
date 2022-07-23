#include <bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long a, b;
    cin >> a >> b;
    while (b--)
    {
        if (a % 10 == 0)
            a /= 10;
        else
            --a;
    }
    cout << a;
    return 0;
}