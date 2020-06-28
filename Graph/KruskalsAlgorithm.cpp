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

//comparater function
//which used as call back function
//to sort according to weights of the edge
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

//this will find the parent of every node
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

    //output array
    Edge *output = new Edge[n - 1];
    //parent array used to detect the cycle in the graph
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
        if (srcParent != destParent) // if true  then it is safe i.e no cycle
        {
            //insert in the output array
            output[count] = currEdge;
            ++count;
            //now change the parent b/c these are connected
            //for future use
            parent[srcParent] = destParent;
        }
        ++i;
    }

    //print the array
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