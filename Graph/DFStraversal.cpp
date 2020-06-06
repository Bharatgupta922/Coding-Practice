#include <iostream>
#include <vector>
#include <list>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
vector<int> DFStraversal(vector<int> adj[], int source, bool visited[])
{
    static vector<int> result;
    visited[source] = true;
    result.push_back(source);

    for (vector<int>::iterator it = adj[source].begin(); it != adj[source].end(); ++it)
    {
        if (!visited[*it])
        {
            DFStraversal(adj, *it, visited);
        }
    }
    return result;
}
vector<int> traverse(vector<int> adj[], int source, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    return DFStraversal(adj, source, visited);
}
int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    vector<int> adj[n];
    vector<int> result;
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    result = traverse(adj, 0, n);
    cout<<"After DFS traversal"<<endl;
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        cout << *it << " ";
    }
}