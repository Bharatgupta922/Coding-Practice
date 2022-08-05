#include <bits/stdc++.h>
using namespace std;
void main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n == 1)
    {
        cout << "1";
        return;
    }
    int b[n];
    sort(a, a + n);
    b[0] = a[0];

    for (int i = 1; i < n; ++i)
    {
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if (b[i] > b[n - 1])
        {
        }
    }
}

// i dont know how its done
