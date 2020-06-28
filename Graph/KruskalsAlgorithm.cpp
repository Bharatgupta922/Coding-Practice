#include <iostream>
#include <algorithm>
using namespace std;
//GREEDY ALGORITHM
class Edge
{
public:
    // it is an undirected graph
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void KrusKals(Edge *edge, int n, int E)
{
    //sort the array on the basis of weight
    sort(edge, edge + E, compare);

    Edge *output = new Edge[n - 1];
    int *parent = new int[n];

    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    int count = 0, i = 0;
    while (count != n - 1)
    {
        Edge currEdge = edge[i];

        ///check if we can add this edge in the mst
        int srcParent = findParent(currEdge.src, parent);
        int destParent = findParent(currEdge.dest, parent);
        if (srcParent != destParent)
        {
            output[count] = currEdge;
            ++count;
            parent[srcParent] = destParent;
        }
        ++i;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        cout << output[i].src << " -- " << output[i].dest << " = " << output[i].weight << endl;
    }
}

int main()
{
    //example

    //input graph with weight
    //     9 14
    // 0 1 4
    // 0 7 8
    // 1 2 8
    // 1 7 11
    // 7 8 7
    // 7 6 1
    // 2 8 2
    // 8 6 6
    // 2 3 7
    // 6 5 2
    // 2 5 4
    // 3 5 14
    // 3 4 9
    // 4 5 10

    //output
    // 7 6 1
    // 2 8 2
    // 6 5 2
    // 0 1 4
    // 2 5 4
    // 2 3 7
    // 0 7 8
    // 3 4 9
    int n, E;
    cin >> n >> E;
    Edge *edge = new Edge[E];
    for (int i = 0; i < E; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edge[i].src = s;
        edge[i].dest = d;
        edge[i].weight = w;
    }
    KrusKals(edge, n, E);
    return 0;
}