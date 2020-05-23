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
        int a[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[j][i];
        int temp;
        for (int i = 0; i < n; i++)
        {
            temp = a[0][i];
            a[0][i] = a[n - 1][i];
            a[n - 1][i] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
