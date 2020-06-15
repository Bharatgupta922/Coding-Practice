#include <iostream>
using namespace std;
// (3^6) = ((3^2)^3)
int getAns(long long a, long long b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return getAns(a * a, b / 2);
    return a * getAns(a, b - 1);
}
int main()
{
    long long int a, b;
    cout << "Enter the a raise to the power b " << endl;
    cin >> a >> b;
    cout << getAns(a, b);
    return 0;
}