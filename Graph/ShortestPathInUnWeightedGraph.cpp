#include<iostream>
#include<vector>
#include<utility>
#include<climits>
#include<list>
using namespace std ;
void addEdge(vector<int> adj[] ,int u,int v){
    // as it is an undirected graph 
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool CheckbyBFS(vector<int> adj[],int n , int start , int destination , bool visited[] ,int distance[] , int pred[] ){
    for(int i=0;i<n;i++){
        visited[i] = false;
        distance[i] = INT_MAX;
        pred[i] = -1;
    }
    list<int> queue;
    queue.push_back(start);
    visited[start] = true;
    distance[start] = 0;
    while(!queue.empty()){
        int u = queue.front();
        queue.pop_front();
        for(vector<int>::iterator it = adj[u].begin(); it!=adj[u].end() ; ++it){
            if(!visited[*it]){
                visited[*it] = true;
                queue.push_back(*it);
                distance[*it] = distance[u]+1;
                pred[*it] = u;
            }
            if(*it == destination){
                return true;
            }
        }
    }
return false;
}
void printShortestdistance(vector<int> adj[] , int n , int start ,int destination){
    int distance[n] , pred[n];
    bool * visited = new bool[n];

if(CheckbyBFS(adj,n,start,destination,visited,distance,pred)==false){
    cout<<"Sorry ! that your graph didnt have connected edges with destination node "<<endl;
    cout<<" or it do not have the destination node"<<endl;
    return ;
}

vector<int> vec;
int crawl  = destination;
vec.push_back(destination);
while(pred[crawl] != -1){
    vec.push_back(pred[crawl]);
    crawl = pred[crawl];
}

cout<<"the Shortest distance between "<<start<<" and "<<destination<<" is : ";
cout<<distance[destination]<<endl;

cout<<"the shortest path between "<<start<<" and "<<destination<<" is : ";
for(vector<int>::reverse_iterator it = vec.rbegin(); it!=vec.rend() ; ++it){
    cout<<*it<<" ";
}
cout<<endl;

}
int main(){
        int n,start,destination;
    cout<<"Enter the number of nodes you want "<<endl;
    cin>>n;
    cout<<"Enter the starting and destination point "<<endl;
    cin>>start>>destination;
    vector<int> adj[n] ;
    addEdge(adj,0,1);
    addEdge(adj,0,5);
    addEdge(adj,1,5);
    addEdge(adj,1,2);
    addEdge(adj,5,4);
    addEdge(adj,2,4);
    addEdge(adj,2,3);
    addEdge(adj,4,3);
    addEdge(adj,5,2);
    printShortestdistance(adj,n,start,destination);
    return 0;
}
 //'
// #include<iostream>
// #include<list>
// #include<vector>
// #include<utility>
// using namespace std;
// void addEdge(vector<int> adj[] ,int u,int v){
//     // as it is an undirected graph 
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// int shortestPath(vector<int> adj[] ,int start,int n,int destination){
// bool * visited = new bool[n];
// for(int i=0;i<n;i++){
//     visited[i] = false;
// }
// list<pair<int,int> > queue;
// int distance_covered = 0;
// pair<int,int> source (start , distance_covered);
// queue.push_back(source);
// visited[source.first] = true;
// while(!queue.empty()){
//     source = queue.front();
//     if(source.first == destination){
// return source.second;
//     }
// queue.pop_front();
// for(vector<int>::iterator it = adj[source.first].begin() ; it != adj[source.first].end() ; ++it){
//     if(!visited[*it]){
//         visited[*it] = true;
//        pair<int,int> temp (*it ,distance_covered + 1);
//         queue.push_back(temp);
//     }
// }
// ++distance_covered;
// }
// return -1;
// }
// int main(){
//     int n,start,destination;
//     cout<<"Enter the number of nodes you want "<<endl;
//     cin>>n;
//     cout<<"Enter the starting and destination point "<<endl;
//     cin>>start>>destination;
//     vector<int> adj[n] ;
//     addEdge(adj,0,1);
//     addEdge(adj,0,5);
//     addEdge(adj,1,5);
//     addEdge(adj,1,2);
//     addEdge(adj,5,4);
//     addEdge(adj,2,4);
//     addEdge(adj,2,3);
//     addEdge(adj,4,3);
//     addEdge(adj,5,2);
//     cout<<"the shortest distance between "<<start<<" and "<<destination<<" is :"<<endl;
//     cout<<shortestPath(adj,start,n,destination);

//     return 0;
// }