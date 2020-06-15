#include <iostream>
#include <vector>
#include <queue>
//this is basically BFS based topological sorting
///as topological sort using DFS is not suitable the cyclic graphs
//this algo is also used to detect the cycle in directed graph
using namespace std;
void addEdge(vector<int> vec[], char u, char v)
{
    //since it is undirected graph
    vec[u].push_back(v);
}
void tsort(vector<int> adj[], int n)
{
    vector<int> in_degree(n, 0);

    //it will mark the degree of each node
    for (int i = 0; i < n; i++)
    {
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
        {
            ++in_degree[*it];
        }
    }
    queue<int> q;
    int count = 0;
    vector<int> topOrder;
    // we want to first print the elements which are 0 degree
    for (int i = 0; i < n; ++i)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topOrder.push_back(u);
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            if (--in_degree[*it] == 0)
            {
                q.push(*it);
            }
        }
        ++count;
    }
    //check for cyclic and ayclic
    if (count != n)
    {
        cout << "This Graph does contain a cycle" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << (char)(topOrder[i] + 'A') << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of nodes you want " << endl;
    cin >> n;
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 5);
    addEdge(adj, 6, 0);
    addEdge(adj, 6, 1);
    addEdge(adj, 1, 7);
    addEdge(adj, 6, 2);
    addEdge(adj, 3, 2);
    addEdge(adj, 8, 2);
    addEdge(adj, 3, 7);
    addEdge(adj, 3, 8);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 8);
    addEdge(adj, 9, 4);
    tsort(adj, n);
    return 0;
}