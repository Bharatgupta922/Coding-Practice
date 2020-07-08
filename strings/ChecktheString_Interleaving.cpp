#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        cout << isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends

/*You are required to complete this method */
bool isInterleave(string a, string b, string c)
{
    if ((!a.length()) && (!b.length()) && (!c.length()))
    {
        return true;
    }
    if (!c.length())
        return false;
    bool x = a.length() && a[0] == c[0] && isInterleave(a.substr(1), b, c.substr(1));
    bool y = b.length() && b[0] == c[0] && isInterleave(a, b.substr(1), c.substr(1));
    return x || y;
}
