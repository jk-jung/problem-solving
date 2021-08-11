#include <string.h>
#include <stdio.h>
#include <math.h>
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
#define pb    emplace_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

class DisjointSetUnion {
public:
    vector<int> p, size;

    DisjointSetUnion(int _n = 0) {
        p.resize(_n), iota(p.begin(), p.end(), 0);
        size.resize(_n), fill(size.begin(), size.end(), 1);
    }

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
};

class LowestCommonAncestor {
public:
    int n, log_n;
    vector<int> depth, *tree;
    vector<vector<int>> parent;

    void init(int _n, vector<int> *_tree) {
        n = _n;
        log_n = 32 - __builtin_clz(n);
        tree = _tree;
        depth.clear(), depth.resize(n + 1);
        parent.clear(), parent.resize(n + 1);
        for (int i = 0; i <= n; i++)parent[i].resize(log_n + 1, -1);

        for (int i = 0; i <= n; i++) {
            if (parent[i][0] == -1) dfs(i, -1);
        }
    }

    int lca(int x, int y) {
        if (depth[x] > depth[y]) swap(x, y);
        for (int i = log_n; i >= 0; i--) {
            if (depth[y] - depth[x] >= (1 << i)) {
                y = parent[y][i];
            }
        }
        if (x == y) return x;
        for (int i = log_n; i >= 0; i--) {
            if (parent[x][i] != parent[y][i]) {
                x = parent[x][i], y = parent[y][i];
            }
        }
        return parent[x][0];
    }

    void dfs(int x, int y) {
        depth[x] = (y == -1 ? 0 : depth[y] + 1);
        build(x, y);
        for (int z : tree[x]) {
            if (z != y) dfs(z, x);
        }
    }

    void build(int x, int y) {
        parent[x][0] = y;
        for (int i = 1; i <= log_n; i++) {
            int z = parent[x][i - 1];
            if (z == -1)break;
            parent[x][i] = parent[z][i - 1];
        }
    }
};

class IndexTree {
public:
    int n, size;
    vector<int> d;

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        while (x) {
            d[x] += v;
            x >>= 1;
        }
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s], s++;
            if ((e & 1) == 0) r += d[e], e--;
            s >>= 1, e >>= 1;
        }
        return r;
    }
};

class FenwickTree {
public:
    vector<int> d;
    void init(int n) {
        d.clear(), d.resize(2 * n + 5);
    }

    void up(int x, int v) {
        for (; x < d.size(); x |= x + 1) d[x] += v;
    }

    int read(int x) {
        int r = 0;
        for(; x >= 0; x = (x & (x + 1)) - 1)
            r += d[x];
        return r;
    }
};

int n, Q;
vector<int> vv[300005];
vector<int> ww[300005];

int s[500005], e[500005], w[500005];
int r[500005], xr[300005];
int p[300005], in[300005], out[300005], ck;

DisjointSetUnion dsu;
LowestCommonAncestor lca;
IndexTree tre;
FenwickTree ftree;


void dfs(int x, int y, int cur) {
    xr[x] = cur;
    p[x] = y;
    in[x] = ck++;

    for (int i = 0; i < vv[x].size(); i++) {
        int z = vv[x][i];
        if (z != y) dfs(z, x, cur ^ ww[x][i]);
    }
    out[x] = ck;
}

void up(int x, int a) {
    while (x != a) {
        ftree.up(in[x], 1);
        ftree.up(out[x], -1);
        x = p[x];
    }
}

void solve() {
    cin >> n >> Q;
    dsu.init(n + 1);

    for (int i = 0; i < Q; i++) {
        cin >> s[i] >> e[i] >> w[i];
        if (dsu.is_same_set(s[i], e[i])) {
            r[i] = 1;
            continue;
        }
        dsu.unite(s[i], e[i]);
        vv[s[i]].pb(e[i]), vv[e[i]].pb(s[i]);
        ww[s[i]].pb(w[i]), ww[e[i]].pb(w[i]);
    }

    lca.init(n + 1, vv);
//    tre.init(n + 1);
    ftree.init(n + 1);

    for (int i = 1; i <= n; i++)
        if (p[i] == 0) dfs(i, -1, 0);

    for (int i = 0; i < Q; i++) {
        if (r[i] == 0) {
            cout << "YES\n";
        } else {
            int x = s[i], y = e[i];
            int t = xr[x] ^ xr[y] ^ w[i];
            if (t == 0) {
                cout << "NO\n";
                continue;
            }

            int a = lca.lca(x, y);
            t = ftree.read(in[x]) + ftree.read(in[y]) - 2 * ftree.read(in[a]);
            if (t > 0) {
                cout << "NO\n";
                continue;
            }

            up(x, a);
            up(y, a);
            cout << "YES\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
