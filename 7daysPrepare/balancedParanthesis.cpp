#include <bits/stdc++.h>
using namespace std;
// balanced or not paranthesis

bool balanced(string a)
{
    stack<char> s;
    char x;
    bool ans = true;
    for (int i = 0; i < s.size() && ans; ++i)
    {
        if (a[i] == '[' || a[i] == '{' || a[i] == '(')
        {
            s.push(a[i]);
            continue;
        }
        if (s.empty())
        {
            ans = false;
            break;
        }
        switch (a[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
            {
                ans = false;
            }
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
            {
                ans = false;
            }
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
            {
                ans = false;
            }
            break;
        }
    }
    if (s.empty() && ans)
        return true;
    return false;
}
int main()
{
    // 6
    // 3 2 6 5 0 3

    // #ifndef ONLINE_MODE
    //    freopen("input.txt" , "r", stdin);
    //    freopen("output.txt","w",stdout);
    // #endif

    string s = "[[[]]{}()({}{[]})]";

    balanced(s) ? cout << "balanced" : cout << "not balanced";

    return 0;
}
