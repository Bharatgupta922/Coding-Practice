#include <iostream>
#include <stack>
using namespace std;
void printmiddle(stack<int> s)
{
    cout << endl;
    int count = s.size() / 2;
    while (count--)
        s.pop();
    cout << s.top() << endl;
    return;
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
    printmiddle(s);
    return 0;
}
