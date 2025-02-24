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


int n;
vector<pair<ll, ll>> v[100005];
ll d[100005];
ll dfs(int x, int p = -1) {
    ll r = 0;
    for (auto i: v[x]) {
        if (i.F == p) continue;
        r = max(r, i.S + dfs(i.F, x));
    }
    return r;
}

void solve() {
    cin >> n;

    ll r = 0;
    for (ll i = 0, a, b, c; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].pb(mp(b, c));
        v[b].pb(mp(a, c));
        r += c * 2;
    }
    cout << r - dfs(1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
