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
} md(200000, MOD);


const int MAX = 200000;
map<int, int> fac[MAX + 5];

void fast_factorization_for_many_numbers() {
    vector<int> prime(MAX + 1);
    for (int i = 2; i <= MAX; i++) {
        if (prime[i])continue;
        for (int j = i + i; j <= MAX; j += i) prime[j] = i;
    }

    for (int i = 2; i <= MAX; i++) {
        int x = i;
        while (prime[x]) fac[i][prime[x]]++, x /= prime[x];
        if (x > 1) fac[i][x]++;
    }
}

ll rr = 0;
int n;
vector<tuple<int, int, int>> v[MAX + 5];

void lcm(map<int, int> &a, map<int, int> &b) { for (auto[k, x]: b)a[k] = max(a[k], x); }

void divide(map<int, int> &a, map<int, int> &b) {
    for (auto[k, x]: b){
        if(a[k] == x) {
            a.erase(k);
        }else a[k] -= x;
    }
}

void mul(map<int, int> &a, map<int, int> &b) { for (auto[k, x]: b)a[k] += x; }

map<int, int> dfs(int x, int y = -1) {
    map<int, int> r;
    for (auto[z, a, b]: v[x]) {
        if (z == y)continue;

        map<int, int> t = dfs(z, x);
        lcm(t, fac[b]);
        divide(t, fac[b]);
        mul(t, fac[a]);

        if(r.size() < t.size())swap(r, t);
        lcm(r, t);
    }
    return r;
}

void go(int x, int y, ll r) {
    rr = (rr + r) % MOD;

    for (auto[z, a, b]: v[x]) {
        if (z == y)continue;

        ll nt = r * md.inv(a) % MOD * b % MOD;
        go(z, x, nt);
    }
}

void solve() {
    cin >> n;
    for (int i = 0, a, b, x, y; i < n - 1; i++) {
        cin >> a >> b >> x >> y;
        int g = gcd(x, y);
        x /= g;
        y /= g;
        v[a].pb(make_tuple(b, x, y));
        v[b].pb(make_tuple(a, y, x));
    }

    map<int, int> x = dfs(1);
    ll r = 1;
    for (auto[k, y]: x) {
        r = (r * md.pow(k, y)) % MOD;
    }

    rr = 0;
    go(1, -1, r);
    cout << rr << endl;

    for (int i = 1; i <= n; i++)v[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fast_factorization_for_many_numbers();

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
