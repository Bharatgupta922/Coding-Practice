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
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        mp[s[i]]++;
    }
    mp.size() % 2 == 0? cout << "CHAT WITH HER!" : cout << "IGNORE HIM!";
    return 0;
}