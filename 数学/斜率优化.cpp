// Convex Hull Trick
struct CHT {
    struct Linear {
        ll a, b;
        Linear(ll a=0, ll b=0): a(a), b(b) {}
        ll operator()(ll x) const { return a*x+b; } 
    };
    deque<Linear> ls;
    void add(ll a, ll b) { // decreasing order of a
        Linear l(a, b);
        assert(ls.size() == 0 or ls.back().a >= l.a);
        while (ls.size() >= 2) {
            const Linear& l1 = ls[ls.size()-2];
            const Linear& l2 = ls.back();
            if ((l.b-l2.b)*(l1.a-l2.a) > (l2.a-l.a)*(l2.b-l1.b)) break;
            ls.pop_back();
        }
        ls.push_back(l);
    }
    ll operator()(ll x) { 
        while (ls.size() >= 2) {
            ll a = ls[0](x);
            ll b = ls[1](x);
            if (a < b) break; // get min
            ls.pop_front();
        }
        return ls[0](x);
    }
};
