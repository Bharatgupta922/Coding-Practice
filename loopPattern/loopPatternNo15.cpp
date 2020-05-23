#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n - i; j++)
                cout << ".";
            for (int j = 0; j < i; j++)
                cout << s[j];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
