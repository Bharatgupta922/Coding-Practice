#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(int V , vector<int> adj[]){
    vector<int> bfs;
    vector<int> vis(V+1,0);
    for(int i =1;i<=V;++i){ //1-based indexing
    if(!vis[i]){
        stack<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int node  = q.top();
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

void dfsUtil(int node , vector<int> adj[],vector<int> &vis , vector<int> &ans){
    ans.push_back(node);
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfsUtil(it,adj,vis,ans);
        }
    }
}
//another method
vector<int> dfs(int V , vector<int> adj[]){
    vector<int> ans;
    vector<int> vis(V+1,0);
    for(int i = 1 ;  i <= V ; ++i){
        if(!vis[i]){
            dfsUtil(i,adj,vis,ans);
        }
    }
    return ans;
}
bool checkCycleBFSUtil(int s,vector<int> adj[] , vector<int> &vis){
    queue<pair<int,int> > q;
    vis[s] = 1;
    q.push({s,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push({it,node});
                vis[it]=1;
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}
bool checkCycleBFS(int V , vector<int> adj[]){
    vector<int> vis(V+1,0);
    for(int i = 1 ;  i <= V ; ++i){
        if(!vis[i]){
            if(checkCycleBFSUtil(i,adj,vis))return true;
        }
    }
    return false;
}
bool checkBipartiteUtil(int s , vector<int>  adj[] , int color[]){
queue<int> q;
q.push(s);
color[s] = 1;
while(!q.empty()){
    int node =  q.front();
    q.pop();
    for(auto it : adj[node]){
        if(color[it] == -1){
            color[it] = 1 - color[node];
            q.push(it);
        }else if(color[it] == color[node]){
            return false;
        }
    }
}
return true;
}
bool checkBipartite(int V , vector<int> adj[]){
    int color[V];
    memset(color,-1,sizeof(color));
    for(int i = 0  ; i < V ; ++i){ //zero based indexing 
        if(color[i] == -1){
            if(!checkBipartiteUtil(i,adj,color))return false;
        }
    }
}
bool checkCycleDirectedDFSUtil(int node , vector<int> adj[] , int vis[] , int dfsVis[]){
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkCycleDirectedDFSUtil(it , adj,vis,dfsVis))return true;
        }else if(dfsVis[it])return true;
    }
    dfsVis[node]=0;
    return false;
}
bool checkCycleDirectedDFS(int V , vector<int> adj[]){
    int vis[V] , dfsVis[V];
    memset(vis,0,sizeof vis);
    memset(dfsVis , 0 , sizeof dfsVis);
    for(int i = 0 ; i < V ; ++i){
        if(!vis[i]){
            if(checkCycleDirectedDFSUtil(i,adj,vis,dfsVis))return true;
        }
    } 
    return false;
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