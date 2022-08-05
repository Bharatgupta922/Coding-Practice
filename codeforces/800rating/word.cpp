#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int count1 = 0, count2 = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            count1++;
        else
            count2++;
    }
    if (count1 >= count2)
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    else
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s;
    return 0;
}