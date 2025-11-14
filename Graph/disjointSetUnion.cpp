#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        // combine hashes of both elements
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};


class Union {
    public:
    vector<int> pr, sz;
    int numberOfComponents;

    Union (int n) {
        pr.resize(n);
        sz.resize(n);
        this->numberOfComponents = n;
        for (int i =0 ; i < n; ++i)
        {
            pr[i] = i;
            sz[i] = 1;
        }
    }

    bool findUnion (int u, int v) {
        return root(u) == root(v);
    }

    int root (int i) {
        if (pr[i] == i) return i;
        return pr[i] = root(pr[pr[i]]);
    }

    int un (int u, int v) {
        u = root(u);
        v = root(v);

        if (u == v) return 0;
        if (sz[u] < sz[v])
        swap(u,v);

        pr[v] = pr[u];
        numberOfComponents--;
        sz[u] = sz[u] + sz[v];
        return 1;
    }
};

int main()
{

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int n; cin >> n;
	Union dsu(n);
    // cout<<"fdsvsdvcsd";
    // dsu.un(1, 2);
    // dsu.findUnion(1, 2) ? cout <<"true \n" : cout <<"false" << '\n';
    // dsu.findUnion(2, 3) ? cout <<"true \n" : cout <<"false" << '\n';
    // dsu.un(1, 3);
    // dsu.findUnion(2, 3) ? cout << "true \n" : cout << "false" << '\n';



    /// this question is suppose u have n nodes coputers with m edges 
    // now if suppose a spy comes every D days and cut one wire 
    // now you have to tell after each EOD how many number of componenets left


    // sol we will do ulta we will only push those edges which thief not going to cut 
    // and make a union 
    // and then in reverse keep add one one edge and printing the number of components 
    int D;
    vector<vector<int>> edgesToRemove(D);
    int M;
    unordered_set<pair<int, int>, pair_hash > edgesToRemoveSet(D);
    vector<vector<int> > edges(M);
    vector<vector<int> > adj(n);
    for (int i =0;  i < edges.size(); ++i) {
        if (edgesToRemoveSet.find({edges[i][0], edges[i][1]}) != edgesToRemoveSet.end()) {
            // adj[edges[i][0]].push_back(edges[i][1]);
            // adj[edges[i][0]].push_back(edges[i][1]);
            dsu.un(edges[i][0], edges[i][1]);
        }
    }

    cout<<dsu.numberOfComponents<<endl;
    for (int i =0 ; i < edgesToRemove.size(); ++i) {
        dsu.un(edgesToRemove[i][0], edgesToRemove[i][1]);
        cout<<dsu.numberOfComponents<<endl;
    }
    

    return 0;
}