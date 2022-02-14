#include <iostream>
using namespace std;
bool ispowerof2(int n)
{
    return (n && !(n & (n - 1)));
}
int main()
{

    int ip;
    cin >> ip;
    ispowerof2(ip) ? cout << "It is power of 2" << endl : cout << "It is not a power of 2" << endl;
    return 0;
}