#include<iostream>
#include<stack>
#include<vector>
// this is DFS algorithm 
///topological soring only works for Directed Acyclic Graph 
//so it is also used to detect 
using namespace std ;
void addEdge(vector<int> vec[] ,char u , char v){
    //since it is undirected graph 
    vec[u].push_back(v);
}
void topologicalSort(vector<int> v[] , bool visited[] , stack<int> &s , int i){
    visited[i] = true;
    for(auto it = v[i].begin() ; it!=v[i].end() ; ++it){
        if(!visited[*it])
            topologicalSort(v,visited,s,*it);
        
    }
    s.push(i);
}
void tsort(vector<int> v[] , int n ){
    bool * visited = new bool[n];
    for(int i = 0; i < n ; ++i){
visited[i]  = false;
    }
    stack<int> s;
    for(int i = 0 ; i < n ; ++i){
if(visited[i] == false){
    topologicalSort(v,visited,s ,i);
}
    }
    while(!s.empty()){
        cout<<(char)(s.top()+'A')<<" ";
        s.pop();
    }
}
int main(){
    int n ;
    cout<<"Enter the number of nodes you want "<<endl;
    cin>>n;
     vector<int> v[n];
    addEdge(v,0,1);
    addEdge(v,0,5);
    addEdge(v,6,0);
    addEdge(v,6,1);
    addEdge(v,1,7);
    addEdge(v,6,2);
    addEdge(v,3,2);
    addEdge(v,8,2);
    addEdge(v,3,7);
    addEdge(v,3,8);
    addEdge(v,3,4);
    addEdge(v,4,8);
    addEdge(v,9,4);
   tsort(v,n);
    return 0;
}