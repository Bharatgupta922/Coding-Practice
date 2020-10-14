#include <iostream>
using namespace std;
int main()
{

    unsigned long long t;
    cin >> t;
    while (t--)
    {
        unsigned long long i = 0, q, n, left = 0, index;
        cin >> n >> q;
        int a[n];
        for (unsigned long long j = 0; j < n; ++j)
        {
            cin >> a[j];
        }
        i = 0;
        while (1)
        {
            if (i < n)
            {
                a[i] += left;
                left = 0;
                if (a[i] >= q)
                {
                    a[i] -= q;
                }
                else
                {
                    index = i;
                    break;
                }
                left += a[i];
                ++i;
            }
            else
            {
                i += (int)left / q;
                index = i;
                break;
            }
        }
        cout << index + 1 << endl;
    }

    return 0;
}