#include <bits/stdc++.h>
using namespace std;
bool isvowel(char x)
{
    return x == 'A' ||
           x == 'O' ||
           x == 'Y' ||
           x == 'E' ||
           x == 'U' ||
           x == 'I' ||
           x == 'a' ||
           x == 'o' ||
           x == 'y' ||
           x == 'e' ||
           x == 'u' ||
           x == 'i';
}
int main()
{
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < s.length(); ++i)
    {
        if (!isvowel(s[i]))
        {
            ans.push_back('.');
            ans.push_back(tolower(s[i]));
        }
    }
    cout << ans;

    return 0;
}