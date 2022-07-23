#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    if (s[0] >= 'a' && s[0] <= 'z')
        s[0] = s[0] - 32;
    cout << s;
    return 0;
}