#include <bits/stdc++.h>
using namespace std;
int findMinVertex(int *weights, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false && (minVertex == -1 || weights[i] < weights[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int **edges, int n)
{

    int *parent = new int[n];
    int *weight = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; ++i)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < n - 1; ++i)
    {

        int minVertex = findMinVertex(weight, visited, n);+
        visited[minVertex] = true;
        for (int j = 0; j < n; ++j)
        {
            if (edges[minVertex][j] != 0 && visited[j] == false)
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < n; ++i)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << "--" << i << "-->" << weight[i] << endl;
        }
        else
        {
            cout << i << "--" << parent[i] << "-->" << weight[i] << endl;
        }
    }
}
int main()
{
    // sample input
    // 5 7
    // 0 1 4
    // 0 2 8
    // 1 3 6
    // 1 2 2
    // 2 3 3
    // 2 4 9
    // 3 4 5

    // output
    // 0--1-->4
    // 1--2-->2
    // 2--3-->3
    // 3--4-->5
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    cout << endl;
    prims(edges, n);
    for (int i = 0; i < n; ++i)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}