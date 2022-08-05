#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction = true)
    {
        adj[u].push_back(v);
        if (direction)
            adj[v].push_back(u);
    }
    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ,";
            }
            cout << endl;
        }
    }
};
int main()
{

#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // 5 6
    // 0 1
    // 1 2
    // 2 3
    // 3 1
    // 3 4
    // 0 4

    int n, m;
    cin >> n >> m;
    graph g;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printAdjList();

    return 0;
}