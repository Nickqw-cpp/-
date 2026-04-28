ll euler_phi(ll n) {
    auto fs = factorize(n);
    ll res = n;
    for (auto [p, _] : fs) res -= res/p;
    return res;
}
