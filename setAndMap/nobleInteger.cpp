// noble integer
/** An integer x is said to be Noble in arr[] if the number of integers greater than x are equal to x. */
#include <iostream>
#include <algorithm>
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] == n - i)
            {
                cout << a[i];
                break;
            }
        }
    }
    return 0; 
}