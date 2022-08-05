#include <bits/stdc++.h>
using namespace std;
int main()
{

    // #ifndef ONLINE_MODE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    string a, b;
    cin >> a >> b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    cout << a.compare(b);

    return 0;
}