#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[n][3];
    int count, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        count = 0;
        for (int j = 0; j < 3; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                count++;
        }
        if (count >= 2)
            sum++;
    }
    cout << sum;

    return 0;
}