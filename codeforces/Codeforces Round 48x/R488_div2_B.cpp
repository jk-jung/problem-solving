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
typedef pair<ll, ll> pi;
typedef vector<ll> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pi> v(n), c(n);
    vector<ll> r(n);
    for (auto &[x, y]: v)cin >> x;
    for (auto &[x, y]: v)cin >> y;
    c = v;
    for (ll i = 0; i < n; i++)c[i].S = i;
    sort(v.begin(), v.end());
    sort(c.begin(), c.end());

    map<ll, ll> ck;
    for (ll i = 0; i < n; i++) {
        auto [x, y] = c[i];
        ll coin = v[i].S;
        r[y] = (ll)coin;

        ll kk = k;
        for (auto [cc, cnt]: ck) {
            ll t = min(cnt, kk);
            r[y] -= (ll)cc * t;
            kk -= t;
            if (kk == 0)break;
        }

        ck[-coin]++;
    }
    for (ll x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
