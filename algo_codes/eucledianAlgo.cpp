#include <bits/stdc++.h>
using namespace std;

// this algorithm is used for finding gcd

// Basic Euclidean Algorithm for GCD
// The algorithm is based on below facts.

// If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change. So if we keep subtracting repeatedly the larger of two, we end up with GCD.
// Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    
    return gcd(b % a, a);
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int result = gcd(a, b);
        cout << result << endl;
    }
    return 0;
}