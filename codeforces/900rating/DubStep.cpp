#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define f(x, n) for (int x = 0; x < n; ++x)
void tokenize(string s, string del = " ")
{
    int start = 0;
    int end = s.find(del);
    while (end != -1)
    {
        cout << s.substr(start, end - start) << " ";
        start = end + del.size();
        end = s.find(del, start);
    }
    cout << s.substr(start, end - start);
}
int main()
{
    fastio();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    tokenize(s, "WUB");
    return 0;
}