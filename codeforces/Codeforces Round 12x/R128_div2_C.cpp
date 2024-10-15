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


void solve() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i] = {x * a + y * b, i + 1};
    }
    sort(v.begin(), v.end());
    vector<ll> r;
    for (auto [x, y]: v)
        if (x <= m) {
            m -= x;
            r.pb(y);
        }
    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
