#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{
    cout << "Enter no. of test cases " << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter the number of items" << endl;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[a[i]]++;
        for (auto x : m)
        {
            if (x.second > 1)
                cout << x.first << " ";
        }
        cout << endl;
    }
    return 0;
}