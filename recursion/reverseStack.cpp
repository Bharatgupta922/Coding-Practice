#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void insertAtBottom(int x)
{
    if (s.empty())
        s.push(x);
    else
    {
        int temp = s.top();
        s.pop();
        insertAtBottom(x);
        s.push(temp);
    }
}
void reverse()
{
    if (s.empty())
        return;
    int temp = s.top();
    s.pop();
    reverse();
    insertAtBottom(temp);
}
int main()
{

    cout << "Enter the number of elements" << endl;
    int n;
    cin >> n;
    cout << "Enter the Elements" << endl;
    while (n--)
    {
        int element;
        cin >> element;
        s.push(element);
    }
    cout << "given stack is :" << endl;
    display(s);
    cout << "reversed stack is :" << endl;
    reverse();
    display(s);
    return 0;
}