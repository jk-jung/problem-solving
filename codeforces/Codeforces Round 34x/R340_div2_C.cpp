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

ll f(pair<ll, ll> a, pair<ll, ll> b) {
    ll x = ab(a.F - b.F);
    ll y = ab(a.S - b.S);
    return x * x + y * y;
}

void solve() {
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<pair<ll, ll>> v(n);

    ll r = 0;
    for (int i = 0; i < n; i++){
        cin >> v[i].F >> v[i].S;
        r = max(r, f({x2, y2}, v[i]));
    }

    for (int i = 0; i < n; i++) {
        ll t = f({x1, y1}, v[i]);
        ll t3 = 0;
        for (int j = 0; j < n; j++) {
            ll t2 = f({x1, y1}, v[j]);
            if (t2 <= t)continue;
            t3 = max(t3, f({x2, y2}, v[j]));
        }
        r = min(r, t + t3);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
