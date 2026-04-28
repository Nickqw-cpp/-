// totient table
vector<int> ps, pf, phi;
void sieve(int mx) {
    pf.resize(mx+1);
    phi.resize(mx+1);
    phi[1] = 1;
    rep(i, mx+1) pf[i] = i;
    for (int i = 2; i <= mx; ++i) {
        if (pf[i] == i) {
            ps.push_back(i);
            phi[i] = i-1;
        }
        rep(j, ps.size()) {
            int x = ps[j]*i;
            if (x > mx) break;
            pf[x] = ps[j];
            if (i%ps[j] == 0) {
                phi[x] = phi[i]*ps[j];
                break;
            }
            phi[x] = phi[i]*(ps[j]-1);
        }
    }
}
