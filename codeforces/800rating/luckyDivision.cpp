#include <bits/stdc++.h>
using namespace std;
bool check(int n)
{
    int div[] = {4, 7, 47, 74, 447, 474, 744, 477, 747, 774};
    int sz = sizeof(div) / sizeof(div[0]);
    for (int i = 0; i < sz; ++i)
    {
        if (n % div[i] == 0)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    check(n) ? cout << "YES" : cout << "NO";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}