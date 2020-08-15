#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
void printTheResult(vector<pair<int, int>> result)
{
    for (auto it : result)
    {
        cout << it.first << " " << it.second << " ";
    }
    cout << endl;
}
void MergeOverlaps(vector<pair<int, int>> sp, int n)
{
    if (sp.size() > 0)
    {
        vector<pair<int, int>> result;
        pair<int, int> temp = *(sp.begin());
        sort(sp.begin(), sp.end());
        result.push_back(sp[0]);
        for (int i = 1; i < sp.size(); ++i)
        {
            if (result.back().second >= sp[i].first)
            {
                result.back().second = max(result.back().second, sp[i].second);
            }
            else
            {
                result.push_back(sp[i]);
            }
        }
        printTheResult(result);
    }
}
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> sp;
        int x, y;
        while (n--)
        {
            cin >> x >> y;
            sp.push_back(make_pair(x, y));
        }
        MergeOverlaps(sp, n);
    }
    return 0;
}