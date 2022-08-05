#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(x, n) for (int x = 0; x < n; ++x)

int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        double n, x, y, a, b;
        cin >> n >> x >> y >> a >> b;
        double one = x * (n / a);
        double two = y * (n / b);
        if (one == two)
            cout << "ANY";
        else if (one < two)
            cout << "PETROL";
        else
            cout << "DIESEL";
        cout << endl;
    }
    return 0;
}