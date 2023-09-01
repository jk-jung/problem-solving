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
    int n;
    cin >> n;
    map<int, int> p;

    for (int i = 2; i <= 70; i++) {
        bool ok = true;
        for (int k = 2; k * k <= i; k++) {
            if (i % k == 0)ok = false;
        }
        if (ok) {
            int idx = p.size();
            p[i] = idx;
        }
    }

    vector<ll> d(1 << p.size());
    d[0] = 1;
    map<int, int> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x]++;
    }
    for (auto [x, y]: v) {
        int z = x;
        vector<ll> nxt(1 << p.size());
        int t = 0;
        ll a = 0, b = 0;
        for (int i = 0; i <= y; i++) {
            if (i % 2)a = (a + md.nCk(y, i)) % MOD;
            else b = (b + md.nCk(y, i)) % MOD;
        }
        for (auto [g, f]: p) {
            int c = 0;
            while (z % g == 0)z /= g, c ^= 1;
            if (c) t |= (1 << f);
        }

        for (int i = 0; i < d.size(); i++) {
            if (d[i] == 0)continue;
            int k = i ^ t;
            nxt[k] = (nxt[k] + d[i] * a) % MOD;
            nxt[i] = (nxt[i] + d[i] * b) % MOD;
        }
        d = nxt;
    }

    cout << (d[0] - 1 + MOD) % MOD << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
