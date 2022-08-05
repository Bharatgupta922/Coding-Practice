#include <bits/stdc++.h>
using namespace std;
bool solve()
{
    int a[26] = {0};
    string s;
    cin >> s;
    string x = "hello";
    int i = 0, j = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (x[j] == s[i])
        {
            j++;
            if (j == x.length())
                return true;
        }
    }
    return false;
}
int main()
{
    // #ifndef ONLINE_MODE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    if (solve())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}