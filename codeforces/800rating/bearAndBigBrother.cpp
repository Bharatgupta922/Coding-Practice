#include <bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    int count = 0;
    while (a <= b)
    {
        count++;
        a *= 3;
        b *= 2;
    }
    cout << count;
    return 0;
}