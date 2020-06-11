

#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
void addEdge(list<pair<int,int> > adj[] ,int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
void shortestPath(list<pair<int,int> > adj[] ,int src,int V) 
{ 
    set< pair<int, int> > setds; 
    vector<int> dist(V, INF);
    setds.insert(make_pair(0, src)); 
    // first is weight , second node
    dist[src] = 0; 
    while (!setds.empty()) 
    { 
        pair<int, int> tmp = *setds.begin(); 
        setds.erase(setds.begin());
        int u = tmp.second; 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF) 
                    setds.erase(setds.find(make_pair(dist[v], v))); 
                dist[v] = dist[u] + weight; 
                setds.insert(make_pair(dist[v], v)); 
            } 
        } 
    } 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
int main() 
{ 
    int V = 9; 
    list< pair<int, int> > adj[V]; 
    addEdge(adj , 0, 1, 4); 
    addEdge(adj,0, 7, 8); 
    addEdge(adj,1, 2, 8); 
    addEdge(adj,1, 7, 11); 
    addEdge(adj,2, 3, 7); 
    addEdge(adj,2, 8, 2); 
    addEdge(adj,2, 5, 4); 
    addEdge(adj,3, 4, 9); 
    addEdge(adj,3, 5, 14); 
    addEdge(adj,4, 5, 10); 
    addEdge(adj,5, 6, 2); 
    addEdge(adj,6, 7, 1); 
    addEdge(adj,6, 8, 6); 
    addEdge(adj,7, 8, 7); 
    shortestPath(adj,0,V); 
    return 0; 
} 