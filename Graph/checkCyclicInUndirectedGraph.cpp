#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    //as it is an undirected graph 
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool CheckByDFS(vector<int> adj[], int source, int n, bool visited[], int parent)
{

    visited[source] = true;

    for (auto it = adj[source].begin(); it != adj[source].end(); ++it)
    {
        if (!visited[*it])
        {
            if (CheckByDFS(adj, *it, n, visited, source))
            {
                return true;
            }
        }
        else if (*it != parent)
        {
            return true;
        }
    }
    return false;
}
bool check(vector<int> adj[], int source, int n)
{

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    } 
    for (int u = source; u < n; ++u)
    {
        if (!visited[u])
        {
            if (CheckByDFS(adj, u, n, visited, -1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the number of nodes you want" << endl;
    cin >> n;
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 7);
    addEdge(adj, 6, 7);
    if (check(adj, 0, n))
        cout << "it is cyclic";
    else
        cout << "sorry ! no cycle found";
}