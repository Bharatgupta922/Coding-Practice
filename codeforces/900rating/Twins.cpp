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
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n == 1)
    {
        cout << "1";
        return 0;
    }
    sort(a, a + n, greater<int>());
    int count = 0, currSum = 0;
    double x = sum / 2;
    for (int i = 0; i < n; ++i)
    {
        currSum += a[i];
        count++;
        if (currSum > x)
            break;
    }
    cout << count;
    return 0;
}