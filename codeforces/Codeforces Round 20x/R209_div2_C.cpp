#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


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
} md(100000, MOD);

ll n, k;
bool process(map<int,int> &ck, map<int,int> &ad){
    ll cnt;
    bool r = false;
    for (auto [x, y]: ck) {
        cnt = 0;
        if (ad.count(x)) {
            y += ad[x];
            ad.erase(x);
        }
        while (y % k == 0) {
            r = true;
            y /= k;
            cnt++;
        }
        ad[x + cnt] += y;
    }
    return r;
}


void solve() {

    cin >> n >> k;
    vi v(n);
    ll ss =0;
    for (int &x: v)cin >> x, ss += x;
    sort(v.begin(), v.end());

    ll cc = 0;
    for (int i = 0; i < n - 1; i++)
        cc += v[i];

    map<int, int> ck, ad;
    for (int &x: v)ck[v.back() - x]++;

    while (process(ck, ad)){
        ck = ad;
        ad.clear();
    }
    cc += ad.begin() -> F;
    cc = min(cc, ss);
    cout << md.pow(k, cc) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
