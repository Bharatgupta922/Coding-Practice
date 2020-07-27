#include <iostream>
using namespace std;

//you have two strings x ,y 
// you have to change x into y 
// there are three types of operations that you can perform on x to transform it into y
// that are : delete ,replace and insert
// you have to find the minimum number of operations could perform to do the same task
int min(int a, int b, int c)
{
    return a < b ? a < c ? a : c : b < c ? b : c;
}
int MaxOp(string x, string y, int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (x[m - 1] == y[n - 1])
        return MaxOp(x, y, m - 1, n - 1);
    else
        return 1 + min(MaxOp(x, y, m, n - 1), MaxOp(x, y, m - 1, n), MaxOp(x, y, m - 1, n - 1));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        cout << MaxOp(x, y, x.length(), y.length()) << endl;
    }
    return 0;
}