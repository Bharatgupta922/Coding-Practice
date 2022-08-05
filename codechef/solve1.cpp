#include <bits/stdc++.h>
using namespace std;
int solve(int n, int x)
{
    if (n < x)
        return 0;
    return (n - x) % 4 == 0 ? (n - x) / 4 : (n - x) / 4 + 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        cout << solve(n, x) << endl;
    }

    return 0;
}