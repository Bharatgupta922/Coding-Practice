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
        int ip[n];
        int op[n];
        int mx = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            cin >> ip[i];

            mx = max(mx, ip[i]);
            cout << mx << " ";
        }
        cout << endl;
    }

    return 0;
}