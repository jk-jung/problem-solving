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


ll check(vi &v) {
    vector<ll> d(v.size());
    for (ll i = 1, s = v[0]; i < v.size(); i++) {
        d[i] = s + d[i - 1];
        s += v[i];
    }
    ll r = 1ll << 60;
    for (ll i = (int) v.size() - 1, s = 0, t = 0; i >= 0; i--) {
        t += s;
        r = min(r, t + d[i]);
        s += v[i];
    }

    return r;
}

ll calc(vi &v, ll f) {
    vi cur;
    ll s = 0, r = 0;
    for (int x: v) {
        s += x % f;
        cur.pb(x % f);
        if (s >= f) {
            ll remain = s - f;
            cur.back() -= remain;
            r += check(cur);
            cur.clear();
            if (remain) cur.pb(remain);
            s = remain;
        }
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    ll s = 0;
    for (int &x: v)cin >> x, s += x;
    if (s == 1) {
        cout << -1 << endl;
        return;
    }

    vector<ll> fac;
    for (ll i = 2; i * i <= s; i++) {
        if (s % i == 0)fac.pb(i);
        while (s % i == 0)s /= i;
    }
    if (s != 1)fac.pb(s);

    ll r = 1ll << 60;
    for (ll x: fac)r = min(r, calc(v, x));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
