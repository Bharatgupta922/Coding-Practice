#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V, vector<int>(V, INT_MAX));
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int n, int E, vector<vector<int>> &graph)
{
    int *weight = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    weight[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(weight[0], 0));
    for (int i = 1; i < n; ++i)
    {
        pq.push(make_pair(INT_MAX, i));
    }
    int sum = 0;
    while (!pq.empty())
    {
        pair<int, int> temp = pq.top();
        pq.pop();
        if (!visited[temp.second])
        {
            sum += weight[temp.second];
            visited[temp.second] = true;
            for (int j = 0; j < n; ++j)
            {
                if (graph[temp.second][j] != INT_MAX && !visited[j] && graph[temp.second][j] < weight[j])
                {
                    weight[j] = graph[temp.second][j];
                    pq.push(make_pair(weight[j], j));
                }
            }
        }
    }
    return sum;
}