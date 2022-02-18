#include<bits/stdc++.h>
using namespace std;
void adjacencyMatrix(){
    
    //adjacency matrix
    int n , m;
    cin>>n>>m;

    int a[n+1][n+1];
    memset(a,0,sizeof(a));
    for(int i = 0; i < m ; ++i){
        int u,v;
        cin>>u>>v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

}
void adjacencyList(){
    int n , m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0 ;  i< m ; ++i){
        int u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[u].push_back(v); // for directed graph please avoid this
    }

    vector<pair<int, int > > adjW[n+1];
    for(int i = 0 ;  i< m ; ++i){
        int u ,v,w;
        cin>>u>>v>>w;
        adjW[u].push_back({v,w});
        adjW[u].push_back({v,w}); // for directed graph please avoid this
    }
    
}
int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 


    return 0;
}