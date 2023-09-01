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
ll n, t, k;

ll cnt(ll s, ll e) {
    return e / t - (s - 1) / t;
}

void solve() {
    cin >> n >> t >> k;
    vi v(n);
    map<ll, ll> d;
    for (int &x: v) {
        cin >> x;
        d[x]++;
    }
    vector<pair<ll, ll>> vv;
    for (auto [x, y]: d) vv.pb({x, y});
    n = vv.size();
    sort(vv.begin(), vv.end());
    vector<ll> ss(n + 2);
    for (int i = 0; i < n; i++) {
        if (i == 0)ss[i] = vv[i].S;
        else ss[i] = ss[i - 1] + vv[i].S;
    }

    ll r = 0;
    for (int i = 0; i < n; i++) {
        auto [x, y] = vv[i];
        ll z = x + t * k;
        z -= z % t;
        while (cnt(x, z) <= k)z += t;
//        while (cnt(x, z) >  k)z -= t;
//        while (z < x)z += t;
        int ii = lower_bound(vv.begin(), vv.end(), mp(z - t, 0ll)) - vv.begin();
        int jj = upper_bound(vv.begin(), vv.end(), mp(z - 1, 1ll << 60)) - vv.begin();

        jj--;
        ii = max(ii, i);
        if (ii == n)continue;
        if (ii > jj)continue;
        ll a = ss[jj] - (ii == 0 ? 0 : ss[ii - 1]);
        r += (a * y);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
