// You are given an array A (distinct elements) of size N.
//  Find out the maximum difference between any two elements such that
// //   larger element appears after the smaller number in A.

// Input:
// 2
// 7
// 2 3 10 6 4 8 1
// 6
// 7 9 5 6 3 2

// Output:
// 8
// 2
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], maxDiff = INT_MIN;
        cin >> a[0];
        int min_tillNow = a[0];
        for (int i = 1; i < n; ++i)
        {
            cin >> a[i];
            maxDiff = max(maxDiff, a[i] - min_tillNow);
            min_tillNow = min(min_tillNow, a[i]);
        }
        cout << maxDiff << endl;
    }
    return 0;
}