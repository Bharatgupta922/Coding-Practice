#include <iostream>
using namespace std;
int _lis(int a[], int n, int *max)
{
    if (n == 1)
        return 1;
    int max_length, res;
    for (int i = 1; i < n; ++i)
    {
        res = _lis(a, i + 1, max);
        if (a[i - 1] < a[n - 1] && res + 1 > max_length)
        {
            max_length = res + 1;
        }
    }
    if (*max < max_length)
    {
        *max = max_length;
    }
    return *max;
}
int lis(int a[], int n)
{
    int max = 1;
    _lis(a, n, &max);
    return max;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cout << lis(a, n) << endl;
    }
    return 0;
}