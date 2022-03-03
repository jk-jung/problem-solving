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

const int mod = 1000000007;


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
    ll tot = 0, tar;
    vi v(n);
    for (int &x: v)cin >> x, tot += x;

    if (tot % n) {
        cout << 0 << endl;
        return;
    }
    tar = tot / n;
    map<int, int> aa, bb;
    int a = 0, b = 0;
    for (int x: v) {
        if (x < tar) a++, aa[x]++;
        if (x > tar) b++, bb[x]++;
    }

    if (a <= 1 || b <= 1) {
        ll r = 1;
        r = (r * md.nCk(n, n - a - b));
        n = a + b;
        for (auto[_, x]: aa) {
            r = (r * md.nCk(n, x)) % mod;
            n -= x;
        }
        for (auto[_, x]: bb) {
            r = (r * md.nCk(n, x)) % mod;
            n -= x;
        }

        cout << r << endl;
    } else {
        ll r = 2;
        r = (r * md.nCk(n, n - a - b));
        for (auto[_, x]: aa) {
            r = (r * md.nCk(a, x)) % mod;
            a -= x;
        }
        for (auto[_, x]: bb) {
            r = (r * md.nCk(b, x)) % mod;
            b -= x;
        }

        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
