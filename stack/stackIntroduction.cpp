#include <iostream>
#include <stack>
using namespace std;
void show(stack<int> s)
{
    cout << endl;
    while (!s.empty())
    {
        cout << s.top() << "  ";
        s.pop();
    }
}
int main()
{
    int n;
    stack<int> s;
    cin >> n;
    while (n--)
    {
        int i;
        cin >> i;
        s.push(i);
    }
    show(s);
    cout << endl
         << "the size of stack is " << s.size();
    cout << endl
         << "the first element is " << s.top();
    s.pop();
    cout << endl
         << "after popping the first element";
    show(s);
    return 0;
}
