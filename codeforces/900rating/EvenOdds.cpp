#include <bits/stdc++.h>
using namespace std;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    if (k <= (n / 2))
        k += (k - 1);
    else
    {
        if (n % 2 == 0)
            k -= (n - k);
        else
            k -= (n - k + 1);
    }
    cout << k;
    return 0;
}