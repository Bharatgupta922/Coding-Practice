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
    int count = 0;
    while (n != 0)
    {
        if (n >= 5)
            n -= 5;
        else if (n >= 4)
            n -= 4;
        else if (n >= 3)
            n -= 3;
        else if (n >= 2)
            n -= 2;
        else
            n -= 1;
        count++;
    }
    cout << count;
    return 0;
}