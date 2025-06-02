struct BIT {
    int n;
    vector<ll> f;
    BIT(int _n)
    {

       n = _n;

       f =  vector<ll>(n+1, 0);

    }
    void update(int i, ll v) {
        for (; i <= n; i += i & -i) f[i] += v;
    }
    ll query(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i) s += f[i];
        return s;
    }
    ll rangeQuery(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};
