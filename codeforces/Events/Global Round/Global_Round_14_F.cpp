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


class DisjointSetUnion {
public:
    vector<ll> p, size;

    DisjointSetUnion(int _n = 0, int *a = NULL) { init(_n, a); }

    void init(int _n, int *a) {
        p.resize(_n), iota(p.begin(), p.end(), 0);
        size.resize(_n);
        for (int i = 0; i < _n; i++) size[i] = a[i];
    }

    int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (size[x] > size[y]) swap(x, y);
        p[x] = p[y], size[y] += size[x];
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
};


ll ss;
int n, m, k;
ll a[300005];
int S[300005];
int E[300005];
int ck[300005];
int vis[300005];
vector<pi> v[300005];
DisjointSetUnion dsu;
vi r, rr;

void dfs(int x) {
    vis[x] = 1;
    for (auto[y, e_id]: v[x]) {
        if (vis[y]) continue;
        dfs(y);

        if (a[x] + a[y] >= k) {
            a[x] = a[x] + a[y] - k;
            r.pb(e_id + 1);
        }else {
            rr.pb(e_id + 1);
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    vector<pi> vv;
    for (int i = 0; i < n; i++) cin >> a[i], ss += a[i], vv.pb({-a[i], i});
    for (int i = 0; i < m; i++) {
        cin >> S[i] >> E[i];
        S[i]--;
        E[i]--;
        v[S[i]].pb({E[i], i});
        v[E[i]].pb({S[i], i});
    }

    if (ss < (ll) (n - 1) * k) {
        cout << "NO\n";
        return;
    }

    dfs(0);
    reverse(rr.begin(), rr.end());
    for(int x: rr)r.pb(x);

    cout << "YES\n";
    assert(r.size() == n - 1);
    for (int x: r)cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
