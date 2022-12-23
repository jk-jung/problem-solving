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
} md(105, MOD);

typedef tuple<ll, ll, ll> tlll;
tlll d[100];
int ck[105];

void add(tlll &a, tlll b) {
    get<0>(a) = (get<0>(a) + get<0>(b)) % MOD;
    get<1>(a) = (get<1>(a) + get<1>(b)) % MOD;
    get<2>(a) = (get<2>(a) + get<2>(b)) % MOD;
}

tuple<ll, ll, ll> go(int n) {
    if (n == 0)return tuple(0, 0, 1);
    if (ck[n]) return d[n];
    ck[n] = 1;

    int m = n / 2;
    // case 1. A: n
    add(d[n], tlll(md.nCk(n - 1, m - 1), 0, 0));

    // case 2. A: n-1, B: n
    auto [x, y, z] = go(n - 2);
    add(d[n], tlll(y, x, z));

    // case 3. B: n, n - 1
    add(d[n], tlll(0, md.nCk(n - 2, m), 0));

    return d[n];
}

void solve() {
    int n;
    cin >> n;
    auto [x, y, z] = go(n);
    cout << x << " " << y << " " << z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
