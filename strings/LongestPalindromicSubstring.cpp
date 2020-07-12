#include <bits/stdc++.h>
using namespace std;
bool isPalin(string s, int i, int j, int n, bool *dp)
{
    return s[i] == s[j] && *((dp + (i + 1) * n) + (j - 1));
}
void LPS(string s)
{
    int n, rows = 0, cols = 0;
    n = s.length();
    int maxlength = 1;
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            maxlength = 2;
            rows = i;
            cols = i + 1;
            dp[i][i + 1] = true;
        }
    }
    int a;
    for (int i = 2; i < n; ++i)
    {
        a = i;
        for (int j = 0; j < n - i && a < n; ++j)
        {
            if (dp[j + 1][a - 1] && s[j] == s[a])
            {
                dp[j][a] = true;
                if (a - j > maxlength)
                {
                    maxlength = a - j + 1;
                    rows = j;
                    cols = a;
                }
            }
            ++a;
        }
    }
    cout << "the length of LPS " << maxlength << " from " << rows << " to " << cols << endl;
    cout << s.substr(rows, cols);
}
int main()
{
    string s;
    cin >> s;
    LPS(s);
}