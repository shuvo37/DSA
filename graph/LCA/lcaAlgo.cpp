#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int level[mx];            // Level
int lca[mx][22];        // Sparse table
int par[mx];            // Parent
vector<int> g[mx];    // Adjacency list

// Depth-First Search to construct the tree and set levels
void dfs(int from, int u, int dep) {
    par[u] = from;
    level[u] = dep;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v == from) continue;
        dfs(u, v, dep + 1);
    }
}

// LCA query function
int lca_query(int N, int a, int b) {


    if (level[a] < level[b]){
         swap(a,b);
    }
  /*  int d=level[a]-level[b];


      while(d>0)
      {
        int i=log2(d);
        a=lca[a][i];
        d-=(1<<i);
      }*/

    log = 1;
    while (1) {
        int next = log + 1;
        if ((1 << next) > level[a])
            break;
        log++;
    }

    for (i = log; i >= 0; i--)
        if (level[a] - (1 << i) >= level[b])
            a = lca[a][i];

    if (a == b)
        return a;

    for (i = log; i >= 0; i--)
        if (lca[a][i] != -1 && lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];

    return par[a];
}

// Initialize the sparse table
void lca_init(int N) {
    memset(lca, -1, sizeof(lca)); // Set -1 to all elements in the array
    int i, j;
    for (i = 0; i < N; i++)
        lca[i][0] = par[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (lca[i][j - 1] != -1)
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
}

int main(void) {
    g[0].pb(1);
    g[0].pb(2);
    g[2].pb(3);
    g[2].pb(4);
    dfs(0, 0, 0);
    lca_init(5);
    printf("%d\n", lca_query(5, 3, 4));
    return 0;
}
