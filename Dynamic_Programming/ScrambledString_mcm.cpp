#include <iostream>
#include <unordered_map>
using namespace std;
bool recursion(string a, string b)
{
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    int n = a.length();
    bool flag = false;
    for (int i = 1; i <= n - 1; ++i)
    {
        bool cond1 = recursion(a.substr(0, i), b.substr(n - i, i)) == true && recursion(a.substr(i, n - i), b.substr(0, n - i)) == true;
        bool cond2 = recursion(a.substr(0, i), b.substr(0, i)) == true && recursion(a.substr(i, n - i), b.substr(i, n - i)) == true;
        if (cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool memoization(string a, string b, unordered_map<string, bool> &mp)
{
    if (a.compare(b) == 0)
    {
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }

    string key = a;
    key.push_back(' ');
    key.append(b);

    if (mp.find(key) != mp.end())
    {
        return mp[key];
    }
    int n = a.length();
    bool flag = false;
    for (int i = 1; i < n; ++i)
    {
        bool cond1 = memoization(a.substr(0, i), b.substr(n - i, i), mp) == true && memoization(a.substr(i, n - i), b.substr(0, n - i), mp) == true;
        bool cond2 = memoization(a.substr(0, i), b.substr(0, i), mp) == true && memoization(a.substr(i, n - i), b.substr(i, n - i), mp) == true;
        if (cond1 || cond2)
        {
            flag = true;
            break;
        }
    }
    return mp[key] = flag;
}

void solve(string x, string y)
{
    bool output;
    unordered_map<string, bool> mp;
    if (x.length() != y.length())
    {
        output = false;
    }
    else if (x.empty() && y.empty())
    {
        output = true;
    }
    else
    {
        // output = recursion(x, y);
        output = memoization(x, y, mp);
    }

    cout << output << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}