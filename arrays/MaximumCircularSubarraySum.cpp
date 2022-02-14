#include <bits/stdc++.h>
using namespace std;
int kadane(int a[], int n)
{
    int MaxSum = INT_MIN, currSum = 0;

    for (int i = 0; i < n; ++i)
    {
        currSum += a[i];
        if (currSum < 0)
        {
            currSum = 0;
        }

        MaxSum = max(MaxSum, currSum);
    }
    return MaxSum;
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

        // Maximum subArray Sum of circular array  = Total sum of array  - sum of non contributing elements;
        // sum of non contributing elements = Maximum subarray Sum using kadane's Algo(-{arr});

        int wrapSum, nonWrapSum;

        nonWrapSum = kadane(a, n);
        int total = 0;
        for (int i = 0; i < n; ++i)
        {
            total += a[i];
            a[i] = -a[i];
        }

        wrapSum = total + kadane(a, n);
        cout << max(wrapSum, nonWrapSum) << endl;
    }

    return 0;
}
