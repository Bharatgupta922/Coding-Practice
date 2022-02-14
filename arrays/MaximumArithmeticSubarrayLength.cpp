#include <iostream>
using namespace std;
// this ques is that : we have to find the length of longest subarray which is also a arithmetic progression
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
        int ans = 2, prev = a[1] - a[0], curr = 2;
        for (int i = 2; i < n; ++i)
        {
            if (prev == a[i] - a[i - 1])
            {
                curr++;
            }
            else
            {
                prev = a[i] - a[i - 1];
                curr = 2;
            }
            ans = max(ans, curr);
        }
        cout << ans << endl;
    }
}