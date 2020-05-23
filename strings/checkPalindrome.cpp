#include <iostream>
using namespace std;
bool checkpalindrome(int l, string s, int h)
{
    if (l == h)
        return true;
    if (l > h)
        true;
    if (s[l] != s[h])
        return false;
    else
        checkpalindrome(++l, s, --h);
}
int main()
{
    string s;
    cin >> s;
    if (checkpalindrome(0, s, s.length() - 1))
        cout << "yes";
    else
        cout << "no";

    return 0;
}
