vector<bool> isp;
vector<int> ps, pf, mu;
void sieve(int mx) {
    isp.resize(mx+1);
    pf.resize(mx+1);
    mu.resize(mx+1);
    mu[1] = 1;
    rep(i, mx+1) pf[i] = i;
    for (int i = 2; i <= mx; ++i) {
        if (pf[i] == i) isp[i] = true, ps.push_back(i), mu[i] = -1;
        rep(j, ps.size()) {
            int x = ps[j]*i;
            if (x > mx) break;
            pf[x] = ps[j];
            if (i%ps[j] == 0) {
                mu[i*ps[j]] = 0;
                break;
            }
            mu[i*ps[j]] = -mu[i];
        }
    }
}
