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
    string x;
    cin >> x;
    if (x.length() == 1)
        cout << "0";
    else
    {
        int f = 0, s = 1, count = 0;
        while (s < n)
        {
            if (x[f] == x[s])
            {
                s++;
                count++;
            }
            else
            {
                f = s;
                s++;
            }
        }
        cout << count;
    }

    return 0;
}