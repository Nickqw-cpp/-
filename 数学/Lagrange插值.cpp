// xi=i 的情况，可以做到 O(n)
struct Interpolation {
    int n;
    vector<mint> a;
    Interpolation() {}
    Interpolation(const vector<mint>& p) {
        n = p.size();
        a.resize(n);
        vector<mint> invf(n, 1);
        mint f = 1;
        for (int i = 1; i < n; ++i) f *= i;
        invf[n-1] = mint(1)/f;
        for (int i = n-1; i >= 1; --i) invf[i-1] = invf[i]*i;
        for (int i = 0; i < n; ++i) {
            mint b = invf[i] * invf[n-1-i];
            a[i] = p[i] * ((n-1-i)%2 == 1 ? -b : b);
        }
    } 
    mint operator()(mint x) const {
        vector<mint> r(n, 1);
        for (int i = n-1; i >= 1; --i) r[i-1] = r[i]*(x-i);
        mint l = 1, res;
        for (int i = 0; i < n; ++i) {
            res += a[i]*l*r[i];
            l *= x-i;
        }
        return res;
    }
};

// 一般情况下求 f(k)，只能做到 O(n2)
struct Interpolation {
    vector<mint> x, y;
    Interpolation() {}
    Interpolation(const vector<mint> x, const vector<mint> y): x(x), y(y) {}
    mint operator()(mint k) {
        int n = x.size();
        mint res;
        rep(i, n) {
            mint a = 1, b = 1;
            rep(j, n) if (j != i) {
                a *= mint(k)-x[j];
                b *= x[i]-x[j];
            }
            res += y[i]*a/b;
        }
        return res;
    }
};
