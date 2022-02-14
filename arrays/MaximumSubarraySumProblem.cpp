#include <bits/stdc++.h>
using namespace std;
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

        //Brute force

        // int mx = INT_MIN;
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = i; j < n; ++j)
        //     {
        //         int sum = 0;
        //         for (int k = i; k <= j; ++k)
        //         {
        //             sum += a[k];
        //         }
        //         mx = max(mx, sum);
        //     }
        // }
        // cout << mx << " " << endl;

        ///cumalative sum

        // int currSum[n + 1];
        // currSum[0] = 0;

        // for (int i = 1; i < n + 1; ++i)
        // {
        //     currSum[i] = currSum[i - 1] + a[i - 1];
        // }

        // int maxSum = INT_MIN;
        // for (int i = 1; i < n + 1; ++i)
        // {
        //     int sum = 0;
        //     for (int j = 0; j < i; ++i)
        //     {
        //         sum = currSum[i] - currSum[j];
        //         maxSum = max(maxSum, sum);
        //     }
        // }
        // cout << maxSum << " " << endl;

        //Kadane's Algorithm

        int currSum = 0;
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (currSum < 0)
            {
                currSum = 0;
            }

            currSum += a[i];
            maxSum = max(maxSum, currSum);
        }
        cout << maxSum << " " << endl;
    }
    return 0;
}