#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    cout << "Enter no. of test cases " << endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n, freq = 0;
        cout << "Enter the number of items" << endl;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << "now enter the frequency " << endl;
        cin >> freq;

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            m[a[i]]++;
        for (auto x : m)
        {
            if (x.second == freq)
                cout << x.first << " ";
        }
        cout << endl;
    }
    return 0;
} // namespace
