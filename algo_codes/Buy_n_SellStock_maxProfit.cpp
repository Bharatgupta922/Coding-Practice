#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n], maxProfit = 0, minPrice = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];

            minPrice = min(a[i], minPrice);

            maxProfit = max(maxProfit, a[i] - minPrice);
        }
        cout << maxProfit << endl;
    }
    return 0;
}