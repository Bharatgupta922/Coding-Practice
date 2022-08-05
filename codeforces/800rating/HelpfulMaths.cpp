#include <bits/stdc++.h>
using namespace std;
vector<int> splitString(string s, string del = " ")
{
    vector<int> ans;
    int start = 0;
    int end = s.find(del);
    while (end != -1)
    {
        ans.push_back(stoi(s.substr(start, end - start)));
        start = end + del.size();
        end = s.find(del, start);
    }
    ans.push_back(stoi(s.substr(start, end - start)));
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    // #ifndef ONLINE_MODE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    string s;
    cin >> s;
    vector<int> ans = splitString(s, "+");
    string res = "";
    for (int i = 0; i < ans.size() - 1; ++i)
    {
        res = res + to_string(ans[i]) + "+";
    }
    res += to_string(ans[ans.size() - 1]);
    cout << res;
    return 0;
}