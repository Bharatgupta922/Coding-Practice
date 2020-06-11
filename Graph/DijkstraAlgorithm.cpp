#include <bits/stdc++.h>
using namespace std;
void addEdge(list<pair<int, int>> adj[], int u, int v, int weight)
{
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight));
}
void ShortestPath(list<pair<int, int>> adj[], int src, int n)
{
    vector<int> dist(n, INT_MAX); //n number of elements in vector with all initialised to INT_MAX
    dist[src] = 0;
    set<pair<int, int>> setds;
    setds.insert(make_pair(dist[src], src)); //as we want to sort w.r.t distance
    while (!setds.empty())
    {
        pair<int, int> temp = *setds.begin();
        setds.erase(setds.begin());
        int u = temp.second;
        for (list<pair<int, int>>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            int node = (*it).first;      //b/c orientation of pair in
            int distance = (*it).second; //array of vector of pair is (nodevalue , weight)
            if (dist[node] > dist[u] + distance)
            {
                if (dist[node] != INT_MAX) //if pair is already visited
                    setds.erase(setds.find(make_pair(dist[node], node)));
                dist[node] = dist[u] + distance;
                setds.insert(make_pair(dist[node], node)); //insert with updation with less weight
            }
        }
    }
    cout << "virteces with Shortest distances from " << src << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
    cout << endl;
}
int main()
{
    int v = 9;
    list<pair<int, int>> adj[v];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    ShortestPath(adj, 0, v);
    return 0;
}