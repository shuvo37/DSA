#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int mx = 1e6;

vector<int> dfs_num;           // Array to track visited status
vector<int> dfs_parent;        // Array to track parent of each node
vector<vector<int>> outEdges;  // Outgoing edges adjacency list
vector<vector<int>> inEdges;   // Incoming edges adjacency list
int numcomp = 0;               // Number of components

void graphCheck(int u) {
    dfs_num[u] = 2;

    for (int j = 0; j < (int)outEdges[u].size(); j++) {
        int v = outEdges[u][j];

        if (dfs_num[v] == 0) {
            dfs_parent[v] = u;
            cout << "Tree Edge " << u << " " << v << endl;
            graphCheck(v);
        } else if (dfs_num[v] == 2 && inEdges[v][dfs_parent[u]] == u) {
            cout << "Bidirectional Edge " << u << " " << v << endl;
        } else if (dfs_num[v] == 2) {
            cout << "Back Edge " << u << " " << v << " (Cycle)" << endl;
        } else if (dfs_num[v] == 1) {
            cout << "Forward/Cross Edge " << u << " " << v << endl;
        }
    }

    dfs_num[u] = 1;
}

int main() {
    int v; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> v;

    dfs_num.assign(v, 0);
    dfs_parent.assign(v, 0);
    outEdges.resize(v);
    inEdges.resize(v);

    int e; // Number of edges
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges in the format 'u v':\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        outEdges[u].push_back(v);
        inEdges[v].push_back(u);
    }

    for (int i = 0; i < v; i++) {
        if (dfs_num[i] == 0) {
            cout << "Component " << ++numcomp << endl;
            graphCheck(i);
        }
    }

    return 0;
}