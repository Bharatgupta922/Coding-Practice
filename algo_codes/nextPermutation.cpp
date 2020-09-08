#include <bits/stdc++.h>
using namespace std;

void nextpermutation(int *a, int n)
{

    if (n != 0 && n != 1)
    {
        int index1 = -1, index2 = -1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (a[i] < a[i + 1])
            {
                index1 = i;
                break;
            }
        }
        if (index1 != -1)
        {
            for (int i = n - 1; i >= 0; --i)
            {
                if (i == index1)
                {
                    break;
                }
                if (a[i] > a[index1])
                {
                    index2 = i;
                    break;
                }
            }
            swap(a[index1], a[index2]);
            sort(a + index1 + 1, a + n);
        }
        else
        {
            sort(a, a + n);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
        nextpermutation(a, n);
    }
    return 0;
}