#include <iostream>
#include <vector>
#include <list>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void BFStraversal(vector<int> adj[], int source, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false; 
    }
    list<int> queue;

    visited[source] = true;
    queue.push_back(source);
    while (!queue.empty())
    {
        source = queue.front();
        cout << source << " ";
        queue.pop_front();
        for (auto it = adj[source].begin(); it != adj[source].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of nodes you want " << endl;
    cin >> n;
    vector<int> adj[n];
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    BFStraversal(adj, 0, 6);

    return 0;
}   