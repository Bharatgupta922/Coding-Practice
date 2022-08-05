#include <bits/stdc++.h>
using namespace std;
bool islucky(long long n)
{
    if (n == 0)
        return false;
    while (n != 0)
    {
        if (n % 10 == 4 || n % 10 == 7)
            n /= 10;
        else
            return false;
    }
    return true;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    islucky(count(s.begin(), s.end(), '4') + count(s.begin(), s.end(), '7')) ? cout << "YES" : cout << "NO";

    return 0;
}