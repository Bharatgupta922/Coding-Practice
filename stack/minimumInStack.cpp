#include <iostream>
#include <climits>
#include <stack>
using namespace std;
int findmax(stack<int> s)
{
    int max = INT_MIN;
    while (!s.empty())
    {
        if (max < s.top())
            max = s.top();
        s.pop();
    }
    return max;
}
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
    stack<int> s;
    int n;
    cin >> n;
    while (n--)
    {
        int i;
        cin >> i;
        s.push(i);
    }
    int max = findmax(s);
    cout << endl
         << "the maximum element in the stack is " << max;
    cout << endl
         << "the stack is ";
    show(s);

    return 0;
}
