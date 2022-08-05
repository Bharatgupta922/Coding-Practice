#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    bool flg = false;
    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        sum = 0;
        for (int j = 0; j < n; ++j)
            sum += a[j][i];
        if (sum != 0)
        {
            flg = true;
            break;
        }
    }
    if (flg)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}