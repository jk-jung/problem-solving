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

ll n, m;
vi v[100005];
ll p[100005];
ll h[100005];
ll a[100005];
ll b[100005];

bool dfs(ll x, ll y = -1) {
    a[x] = b[x] = 0;
    for (ll z: v[x]) {
        if (z == y)continue;
        if (!dfs(z, x)) return false;
        a[x] += a[z];
        b[x] += b[z];
    }

    ll tot = p[x] + h[x] - a[x] + b[x];
    if(tot % 2) return false;
    ll t = tot / 2;
    a[x] += t;
    b[x] += p[x] - t;
    return t >= 0 && b[x] >= 0;
}

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)cin >> p[i];
    for (ll i = 1; i <= n; i++)cin >> h[i];
    for (ll i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    cout << (dfs(1) ? "YES" : "NO") << endl;
    for (ll i = 1; i <= n; i++)v[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
