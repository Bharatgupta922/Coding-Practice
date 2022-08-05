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
    s.find("H") != string::npos || s.find("Q") != string::npos || s.find("9") != string::npos ? cout << "YES" : cout << "NO";

    return 0;
}