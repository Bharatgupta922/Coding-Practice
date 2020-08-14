#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean algorithm also finds integer coefficients x and y such that:

//   ax + by = gcd(a, b)
// Examples:

// Input: a = 30, b = 20
// Output: gcd = 10
//         x = 1, y = -1
// (Note that 30*1 + 20*(-1) = 10)

// Input: a = 35, b = 15
// Output: gcd = 5
//         x = 1, y = -2
// (Note that 35*1 + 15*(-2) = 5)
// The extended Euclidean algorithm updates results of gcd(a, b) using the results calculated by recursive call gcd(b%a, a). Let values of x and y calculated by the recursive call be x1 and y1. x and y are updated using the below expressions.

// x = y1 - ⌊b/a⌋ * x1
// y = x1

//lets find out the gcd for an array using eucledian algorithm

int gcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 1;
        *y = 0;
        return b;
    }
    int x1, y1;
    int g = gcd(b % a, a, &x1, &y1);
    *x = y1 + (b / a) * x1;
    *y = x1;
    return g;
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
        {
            cin >> a[i];
        }
        int result = a[0];
        for (int i = 1; i < n; ++i)
        {
            int x, y;
            result = gcd(result, a[i], &x, &y);
        }
        cout << result << endl;
    }

    return 0;
}