#include <iostream>
using namespace std;
int countBits(int n)
{
    int result = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        result++;
    }
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countBits(n);
    }
}