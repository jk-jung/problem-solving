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

#define MOD 998244353

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
} md(200005, MOD);


class IndexTree {
public:
    int n, size;
    vector<int> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        while (x) d[x] += v, x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s++];
            if ((e & 1) == 0) r += d[e--];
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int kth(int k) {
        int x = 1;
        while (x < size) {
            if (d[x * 2] < k) k -= d[x * 2], x = x * 2 + 1;
            else x *= 2;
        }
        return x - size;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);

    IndexTree tre(200005);
    map<int, int> cnt;
    for (int &x: a)cin >> x, cnt[x]++;
    for (int &x: b)cin >> x;

    ll k = md.fac[n];
    for (auto[kk, x]: cnt) {
        tre.up(kk, x);
        k = (k * md.facInv[x]) % MOD;
    }

    ll r = 0;
    for (int i = 0; i < n && i < m; i++) {
        int x = b[i];
        ll inv = md.inv(n - i);
        ll cnt_x = tre.read(0, x - 1);
        r = (r + k * cnt_x % MOD * inv % MOD) % MOD;

        if (cnt[x] == 0)break;
        int ccc = cnt[x];
        k = k * md.fac[ccc] % MOD * md.facInv[ccc - 1] % MOD * inv % MOD;
        cnt[x]--;
        tre.up(x, -1);
        if (i == n - 1 && n < m)r = (r + 1) % MOD;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
