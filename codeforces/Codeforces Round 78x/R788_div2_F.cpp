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
} md(2000, MOD);


ll n, L, R, z;

class Counter {
public:
    ll limit;
    ll d[65][2005];
//    map<pair<int, ll>, ll> d;

    Counter(ll _limit) : limit(_limit) {
        memset(d, -1,sizeof(d));
    }

    ll calc() {
        return go(60, limit);
    }

    ll go(int idx, ll lim) {
        if(idx == -1)return 1;
        ll val = min(n * 2, lim >> idx);

        ll &r = d[idx][val];
        if(r!=-1)return r;
        r= 0;

        int bit = z >> idx & 1;
        for (int i = bit; i <= min(n, val); i += 2) {
            r = (r + go(idx - 1, lim - (1ll << idx) * i) * md.nCk(n, i)) % MOD;
        }
        return r;
    }
};

void solve() {
    cin >> n >> L >> R >> z;

    ll a = Counter(R).calc();
    ll b = Counter(L - 1).calc();
    ll r = (a - b + MOD) % MOD;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
