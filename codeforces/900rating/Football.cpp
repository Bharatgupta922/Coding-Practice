#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a;
    cin >> a;
    a.find("1111111") == string::npos &&a.find("0000000") == string::npos ? cout << "NO" : cout << "YES";
    return 0;
}