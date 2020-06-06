// A function f is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... n. Given an integer n the task is to print the F(n)th term.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test contains an integer n.
// Input:
// 2
// 5
// 7
// Output:
// 365527
// 6006997207
#include <iostream>
using namespace std;
long long int getSum(int n)
{
    if (n == 0)
        return 0;
    return n + getSum(n - 1);
}
long long int solve(int n)
{
    if (n == 0)
        return 0;
    long long int result = 1, start = getSum(n - 1) + 1;
    for (int i = start; i < start + n; ++i)
        result *= i;
    return result + solve(n - 1);
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}