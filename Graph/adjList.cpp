#include <iostream>
#include <vector>
using namespace std;

// as it is an undirected graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "The links of " << i << " are" << endl;
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
        {
            cout << "->" << *it;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cout << "enter the number of nodes you want" << endl;
    cin >> n;
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    printGraph(adj, n);
    return 0;
}
