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
};


ll n, M;
ll d[404][404];
ll p2[404];

void solve() {
    cin >> n >> M;
    Modular mod(n, M);

    p2[0] = 1;
    for (int i = 1; i <= n; i++)p2[i] = p2[i - 1] * 2 % M;

    d[0][0] = 1;
    d[1][1] = 1;
    d[2][2] = 2;

    for (int i = 3; i <= n; i++) {
        d[i][i] = p2[i - 1];
        for (int j = 1; j <= i; j++) {
            int x = i - j - 1;
            for (int k = 1; k <= x; k++) {
                if(j + k > i)break;
                d[i][j + k] = (d[i][j + k] + p2[j - 1] * mod.nCk(k + j, k) % M * d[x][k] % M) % M;
            }
        }
    }
    ll r = 0;
    for (int i = 0; i <= n; i++)r = (r + d[n][i]) % M;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
