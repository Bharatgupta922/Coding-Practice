#include <iostream>
using namespace std;

int main()
{
    //code

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if ((n & (n + 1)) == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}