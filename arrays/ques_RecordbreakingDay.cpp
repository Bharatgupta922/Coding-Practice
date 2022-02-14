#include <iostream>
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
        int last_max = a[0];
        int ans;
        bool got = false;
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 && a[i + 1] < a[i])
            {
                ans = i;
                got = true;
                break;
            }
            else if (i == n - 1 && a[n - 1] > last_max)
            {
                ans = i;
                got = true;
                break;
            }
            else
            {
                if (a[i] > last_max && a[i + 1] < a[i])
                {
                    ans = i;
                    got = true;
                    break;
                }
            }
            last_max = max(a[i], last_max);
        }
        got ? cout << ans + 1 << " " << endl : cout << "not get the answer" << endl;
    }
    return 0;
}
