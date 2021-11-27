#include <string.h>
#include <stdio.h>
#include <math.h>
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

const ll MAX = 1ll << 60;

class IndexTree {
public:
    int n, size;
    vector<ll> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5, MAX);
    }

    void up(int x, ll v) {
        x += size;
        d[x] = v;
        x /= 2;
        while (x) {
            d[x] = min(d[x * 2], d[x * 2 + 1]), x >>= 1;
        }
    }

    ll read(int s, int e) {
        s += size, e += size;
        ll r = MAX;
        while (s <= e) {
            if ((s & 1) == 1) r = min(r, d[s++]);
            if ((e & 1) == 0) r = min(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }
};

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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


struct Item {
    int s, e, v;
};

bool sf(Item &a, Item &b) {
    return a.s < b.s;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Item> v(m);
    vector<vi> er(n);
    vi a(n);
    for (int i = 0; i < m; i++) {
        cin >> v[i].s >> v[i].e >> v[i].v;
        v[i].s--;
        v[i].e--;
    }
    sort(v.begin(), v.end(), sf);
    IndexTree tre(m);

    for (int i = 0, pos = 0; i < n; i++) {
        while (pos < m && v[pos].s == i) {
            tre.up(pos, v[pos].v);
            er[v[pos].e].pb(pos);
            pos++;
        }
        a[i] = (int) tre.d[1];

        for (int x: er[i]) tre.up(x, MAX);
        er[i].clear();
    }

    ll r = 0;
    for (int k = 0; k < 31; k++) {
        int cnt = 0;

        for (int i = 0; i < n; i++)
            if (a[i] >> k & 1) cnt++;

        if(cnt > 0) {
            ll c1 = md.pow(2ll, cnt - 1);
            ll c2 = md.pow(2ll, n - cnt);

            r = (r + c1 * c2 % MOD * (1<<k)) % MOD;
        }
    }
//    for (int x: a)cout << x << " ";
//    cout << endl;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
