const int D = 50;
struct BitVector {
    vector<ll> d;
    BitVector(): d(D) {}
    void add(ll x) {
        x = getmin(x);
        for (int i = D-1; i >= 0; --i) {
            if (x>>i&1) {
                rep(j, D) if (d[j]>>i&1) d[j] ^= x;
                d[i] = x;
                return;
            }
        }
    }
    ll getmin(ll x) {
        for (int i = D-1; i >= 0; --i) {
            if (x>>i&1) x ^= d[i];
        }
        return x;
    }
    ll calc() {
        ll res = 0;
        rep(i, D) if (d[i]) res ^= d[i];
        return res;
    }
};
