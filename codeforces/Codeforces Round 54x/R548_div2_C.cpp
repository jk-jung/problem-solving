#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

class DisjointSetUnion {
public:
    vector<int> p, size;

    DisjointSetUnion(int _n = 0) { init(_n); }

    void init(int _n) {
        p.resize(_n), iota(p.begin(), p.end(), 0);
        size.resize(_n), fill(size.begin(), size.end(), 1);
    }

    int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

    void unite(int x, int y) {
        if (is_same_set(x, y)) return;
        x = find(x), y = find(y);
        if (size[x] > size[y]) swap(x, y);
        p[x] = p[y], size[y] += size[x];
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
};


#define MOD 1000000007

class Modular {
public:
    ll mod;
    vector<ll> fac, facInv;

    Modular(int n, ll _mod) {
        mod = _mod;
        fac.resize(n + 1), facInv.resize(n + 1);

        fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;

        facInv[n] = inv(fac[n]);
        for (int i = n; i > 0; i--) facInv[i - 1] = facInv[i] * i % mod;
    }

    ll pow(ll x, ll y) {
        ll r = 1;
        for (x = x % mod; y; y >>= 1, x = (x * x) % mod)
            if (y & 1) r = (r * x) % mod;
        return r;
    }

    ll inv(ll x) { return pow(x, mod - 2); }

    ll nCk(ll n, ll k) {
        if (n < k || n < 0 || k < 0) return 0;
        if (k == 0) return 1;
        return fac[n] * facInv[k] % mod * facInv[n - k] % mod;
    }

    ll nHk(ll n, ll k) {
        return nCk(n + k - 1, k);
    }
} md(200000, MOD);


void solve() {
    int n, k;
    cin >> n >> k;
    DisjointSetUnion dsu(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0)dsu.unite(x, y);
    }
    vector<ll> v;
    for (int i = 1; i <= n; i++)if (dsu.find(i) == i)v.pb(dsu.get_size(i));

    ll r = 0;
    for (int i = 2; i <= k; i++) {
        ll rest = md.pow(n, k - i);
        for (ll x: v) {
            r = (r + md.pow(x, i - 1) * (n - x) % MOD * rest) % MOD;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
