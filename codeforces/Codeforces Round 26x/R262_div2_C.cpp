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

void solve() {
    ll n, t, w;
    cin >> n >> t >> w;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;

    ll s = 1, e = 1ll << 31, r = -1;
    while (s <= e) {
        ll m = (s + e) / 2;
        queue<pair<ll, ll>> q;
        ll ss = 0;
        ll need = 0;
        for (int i = 0; i < n; i++) {
            ll x = v[i];
            while (!q.empty() && q.front().F == i) {
                ss -= q.front().S;
                q.pop();
            }
            ll val = x + ss;
            if (val < m) {
                need += m - val;
                ss += m - val;
                q.push({i + w, m - val});
            }
        }
        if (need <= t) s = m + 1, r = m;
        else e = m - 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
