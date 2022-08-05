#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.length() > 10)
        {
            string ans = "";
            ans.push_back(s[0]);
            ans += to_string(s.length() - 2);
            ans.push_back(s[s.length() - 1]);
            cout << ans;
        }
        else
            cout << s;
        cout << endl;
    }

    return 0;
}