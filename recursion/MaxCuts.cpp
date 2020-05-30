#include <iostream>
using namespace std;
int getMax(int a, int b, int c)
{
    return a > b ? a > c ? a : c : b > c ? b : c;
}
int cutMax(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int result = getMax(cutMax(n - a, a, b, c), cutMax(n - b, a, b, c), cutMax(n - c, a, b, c));
    if (result == -1)
        return -1;
    return ++result;
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        cout << cutMax(n, a, b, c) << endl;
    }
    return 0;
}