#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int a[n];
        for (long long int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        long long int minIndex = 0, maxIndex = n - 1, c = a[n - 1] + 1;
        for (long long int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                a[i] += (a[maxIndex] % c) * c;
                --maxIndex;
            }
            else
            {
                a[i] += (a[minIndex] % c) * c;
                ++minIndex;
            }
            cout << a[i] / c << " ";
        }
        cout << endl;
    }
    return 0;
}