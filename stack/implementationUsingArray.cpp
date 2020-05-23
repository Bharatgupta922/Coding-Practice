#include <iostream>
#define N 5
using namespace std;
int stack[N];
int top = -1;
void push(int item)
{
    if (top == N - 1)
        cout << endl
             << "overflow";
    else
        stack[++top] = item;
}
void pop()
{
    if (top == -1)
        cout << endl
             << "underflow";
    else
        --top;
}
int Top()
{
    if (top == -1)
        cout << endl
             << "stack is empty ";
    else
        return stack[top];
}
void show()
{
    int x = top;
    while (x != -1)
    {
        cout << stack[x] << "\t";
        x--;
    }
}
int empty()
{
    if (top == -1)
        return 1;
    return 0;
}
int size()
{
    return top + 1;
}

int main()
{
    int n = N;
    while (n--)
    {
        int i;
        cin >> i;
        push(i);
    }
    show();
    cout << endl
         << "the size of stack is " << size();
    cout << endl
         << "the first element is " << Top();
    pop();
    cout << endl
         << "after popping the first element" << endl;
    show();
    return 0;
}
