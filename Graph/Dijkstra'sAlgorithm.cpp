#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{

    return 0;
}