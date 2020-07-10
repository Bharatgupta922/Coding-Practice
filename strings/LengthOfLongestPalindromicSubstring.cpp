#include <bits/stdc++.h>
using namespace std;
int LengthLongestPalinfdrome(string s, int l, int r)
{
    if (l == r)
    {
        return 1;
    }

    if (s[l] == s[r] && l + 1 == r)
    {
        return 2;
    }

    if (s[l] == s[r])
    {
        return LengthLongestPalinfdrome(s, l + 1, r - 1) + 2;
    }

    return max(LengthLongestPalinfdrome(s, l + 1, r), LengthLongestPalinfdrome(s, l, r - 1));
}
int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        string s;
        cin >> s;
        cout << LengthLongestPalinfdrome(s, 0, s.length() - 1);
    }
    return 0;
}