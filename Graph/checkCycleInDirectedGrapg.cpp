#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    //as it is an directed edge
    adj[u].push_back(v);
}
bool CheckByDFS(vector<int> adj[], int source, bool visited[], bool recStack[])
{
    if (visited[source] == false)
    {
        for (auto it = adj[source].begin(); it != adj[source].end(); ++it)
        {
            visited[source] = true;
            recStack[source] = true;
            if (!visited[*it] && CheckByDFS(adj, *it, visited, recStack))
            {
                return true;
            }
            else if (recStack[*it])
            {
                return true;
            }
        }
    }
    recStack[source] = false;
    return false;
}
bool check(vector<int> adj[], int source, int n)
{
    bool *visited = new bool[n];
    bool *recStack = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = source; i < n; ++i)
    {
        if (CheckByDFS(adj, i, visited, recStack))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    if (check(adj, 0, n))
        cout << "It is cyclic";
    else
        cout << "Sorry! It is not cyclic";

    return 0;
}