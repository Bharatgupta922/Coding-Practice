/* this is the ques. for checking of balanced paranthesis 
in this the input is string oof brackets with characters [,],{,},(,)
the condition is that you have to determine for balance parathesis 
like [()] ,(),{},{()},[{}],etc ,
unbalance paranthesis are (}}},([)],]][[,etc 
the gist is that the 
*the paranthesis which is opened first should be close first * */
#include <iostream>
#include <stack>
#include <string>
#include<vector>

using namespace std;
int main()
{
    bool y = true;
    stack<int> s;
    string a;
    char x;
    cin >> a;
    for (int i = 0; i < a.length() && y; i++)
    {
        y = true;
        if (a[i] == '[' || a[i] == '{' || a[i] == '(')
        {
            s.push(a[i]);
            continue;
        }
        if (s.empty())
        {
            y = false;
            break;
        }
        switch (a[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
            {
                y = false;
            }
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
            {
                y = false;
            }
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x == '{' || x == '(')
            {
                y = false;
            }
            break;
        }
    }
    if (s.empty() && y)
        cout << "balanced";
    else
        cout << "unbalanced";
    return 0;
}
