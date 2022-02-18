#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(int V , vector<int> adj[]){
    vector<int> bfs;
    vector<int> vis(V+1,0);
    for(int i =1;i<=V;++i){ //1-based indexing
    if(!vis[i]){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    }
    return bfs;
}
int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 

     int n , m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0 ;  i< m ; ++i){
        int u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[u].push_back(v); // for directed graph please avoid this
    }

    return 0;
}