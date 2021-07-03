#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define ab(x) (((x)<0)?-(x):(x))

ll mod = -1;
int n;

ll nCm[55][55];
ll fac[55];
ll d[55][1300];
ll s[55][1300];

ll go(int x, int inv) {
    if (x == 0) d[x][inv] = inv == 0 ? 1 : 0;

    ll &r = d[x][inv];
    if (r != -1)return r;
    r = 0;

    for (int i = 0; i < x; i++) {
        ll base = nCm[x - 1][i];
        ll need_inv = inv - (x - i - 1);
        if (need_inv < 0)continue;

        ll nl = min(need_inv, (ll) i * (i - 1) / 2);
        ll nr = (x - i - 1) * (x - i - 2) / 2;

        for (int j = max((ll) 0, need_inv - nr); j <= nl; j++) {
            r = (r + base * go(i, j) % mod * go(x - i - 1, need_inv - j) % mod) % mod;
        }
    }
    return r;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;

    nCm[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) nCm[i][j] = 1;
            else nCm[i][j] = (nCm[i - 1][j - 1] + nCm[i - 1][j]) % mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        int max_inv = i * (i - 1) / 2;
        for (int inv = 0; inv <= max_inv; inv++) {
            s[i][inv] = go(i, inv);
            if (inv > 0) s[i][inv] = (s[i][inv] + s[i][inv - 1]) % mod;
        }
    }
}


ll go2(int m, int need) {
    if (m <= 1) return 0;
    ll r = 0;
    int max_inv = m * (m - 1) / 2;
    for (int i = need; i <= max_inv; i++) {
        r = (r + go(m, i) * s[m][i - need] % mod) % mod;
    }
    return r;
}


ll calc(int x) {
    int m = n - x;

    ll r = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            int need = j - i + 1;
            r = (r + go2(m - 1, need)) % mod;
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(d, -1, sizeof(d));

    cin >> n >> mod;
    init();

    ll r = 0;
    for (int i = 0; i < n - 1; i++) {
        ll base = (nCm[n][i] * fac[i]) % mod;
//        cout << nCm[n][i] << " " << fac[i] << " " << calc(i) << endl;
        r = (r + base * calc(i) % mod) % mod;
    }
    cout << r << endl;
}