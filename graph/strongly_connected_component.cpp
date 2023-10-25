#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mx = 1e6;
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;


void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}


void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}


int main() {
    int n;
    // ... read n ...
    cin >> n;

    // Initialize the adjacency lists with size n
    adj.resize(n);
    adj_rev.resize(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        // ... read next directed edge (a,b) ...
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2(v);

            // Print the strongly connected component
            cout << "Component: ";
            for (auto u : component)
                cout << u << " ";
            cout << endl;

            component.clear();
        }

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n);

    for (auto v : order)
        if (!used[v]) {
            dfs2(v);

            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }

    for (int v = 0; v < n; v++)
        for (auto u : adj[v]) {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v)
                adj_scc[root_v].push_back(root_u);
        }

    // ... rest of the code ...

    return 0;
}

/*

11
1 3
3 7
1 2
2 4
4 1
5 4
5 6
3 4
7 6
6 8
8 7








*/
