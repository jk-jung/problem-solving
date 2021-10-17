#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
    vector<int> p, size;

    DisjointSetUnion(int _n = 0) { init(_n); }

    void init(int _n) {
        p.resize(_n), iota(p.begin(), p.end(), 0);
        size.resize(_n), fill(size.begin(), size.end(), 1);
    }

    int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (size[x] > size[y]) swap(x, y);
        p[x] = p[y], size[y] += size[x];
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
} dsu;

int n, m, q, r;
vector<int> v[300005];
int p[300005];
int ck[300005];
vector<pi> qq;


void dfs(int x, int y) {
    p[x] = y;
    for (int z: v[x]) {
        if (z != y)dfs(z, x);
    }
}

void check(int x) {
    while (x != 1) {
        ck[x] ^= 1;
        x = p[x];
    }
}


void path(int x, vector<int> &t) {
    while (x) {
        t.pb(x);
        x = p[x];
    }
}

void print_path(int s, int e) {
    vector<int> a, b;

    path(s, a);
    path(e, b);

    int root = 0;
    while (a.size() > 0 && b.size() > 0 && a.back() == b.back()) {
        root = a.back();
        a.pop_back();
        b.pop_back();
    }
    reverse(b.begin(), b.end());

    cout << a.size() + b.size() + 1 << '\n';
    for (int x: a)cout << x << " ";
    cout << root << " ";
    for (int x: b)cout << x << " ";
    cout << '\n';
}

int dfs2(int x, int y) {
    int t = ck[x];
    int cnt = 0;
    for (int z: v[x]) {
        if (z == y) continue;
        cnt += dfs2(z, x);
    }

    if (t) {
        if(cnt % 2 == 0) {
            r += cnt / 2;
            return 1;
        } else  {
            r += cnt / 2;
            return 1;
        }
    } else {
        r += (cnt + 1) / 2;
        return 0;
    }
}

void solve() {
    cin >> n >> m;

    dsu.init(n + 1);
    while (m--) {
        int s, e;
        cin >> s >> e;

        if (dsu.is_same_set(s, e))continue;
        dsu.unite(s, e);
        v[s].pb(e);
        v[e].pb(s);
    }

    dfs(1, 0);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int s, e;
        cin >> s >> e;
        qq.pb({s, e});
        check(s);
        check(e);
    }

    bool ok = true;
    for (int i = 1; i <= n; i++)if (ck[i])ok = false;

    if (ok) {
        cout << "YES\n";
        for (auto[s, e]: qq)
            print_path(s, e);
    } else {
        cout << "NO\n";
        dfs2(1, 0);
        cout << r << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
