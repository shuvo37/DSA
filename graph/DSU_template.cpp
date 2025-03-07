struct Dsu
{
    vector<int> par, sz;

    Dsu(int n)
    {
        par = vector<int>(n + 5);
        iota(all(par), 0);
        sz = vector<int>(n + 5, 1);
    }

    int find_par(int ch)
    {
        if (ch == par[ch])
            return ch;
        return par[ch] = find_par(par[ch]);
    }

    int same_set(int u, int v)
    {
        return find_par(u) == find_par(v);
    }

    int connect(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        if (same_set(u, v))
            return 0;
        if (sz[u] > sz[v])
            swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        return 1;
    }
};
