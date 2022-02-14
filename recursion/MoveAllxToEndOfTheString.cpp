#include <iostream>
using namespace std;
string moveLast(string s)
{
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = moveLast(s.substr(1));
    if (ch == 'x')
        return (ans + ch);
    return (ch + ans);
}
int main()
{

    cout << moveLast("abxxxbufvuxjf");
    return 0;
}