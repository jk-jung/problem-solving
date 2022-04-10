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


vi v[200005];
vi dep[200005];
int rt[200005];
ll a[200005];
ll d[200005];

bool sf(int x, int y) {
    return a[x] < a[y];
}

void dfs(int x, int y = -1, int dd = 0) {
    dep[dd].pb(x);
    rt[x] = y;
    for (int z: v[x])if (z != y) dfs(z, x, dd + 1);
}


void check(int dd) {
    vi &t = dep[dd];
    sort(t.begin(), t.end(), sf);

    ll best = 1ll << 50;
    ll fa = a[t[0]];

    for (int x: t) {
        ll cur = 0;
        for (int y: v[x]) if (rt[x] != y) cur = max(cur, d[y]);
        best = min(best, a[x] - cur);

        d[x] = max(d[x], a[x] - fa + cur);
        d[x] = max(d[x], a[x] - best);
    }
}

ll dp(int dd) {
    if (!dep[dd + 1].empty()) dp(dd + 1);

    vi &t = dep[dd];
    sort(t.begin(), t.end(), sf);
    check(dd);

    reverse(t.begin(), t.end());
    for (int x: t)a[x] = - a[x];
    check(dd);

    ll r = 0;
    for (int x: t)
        r = max(r, d[x]);
    return r;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)d[i] = -1;

    for (int i = 2, s; i <= n; i++) {
        cin >> s;
        v[i].pb(s);
        v[s].pb(i);
    }
    for (int i = 2; i <= n; i++)cin >> a[i];

    dfs(1);
    cout << dp(0) << endl;

    for (int i = 0; i <= n; i++)v[i].clear(), dep[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
