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

int n, q;
vi v[200005];


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
        for (int i = 0; i < n; i++)parent[i].resize(log_n + 1, -1);

        for (int i = 0; i < n; i++) {
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

    int up_to(int x, int dep) {
        for (int i = log_n; i >= 0; i--) {
            if (depth[x] - dep >= (1 << i)) {
                x = parent[x][i];
            }
        }
        return x;
    }

    void dfs(int x, int y) {
        depth[x] = (y == -1 ? 0 : depth[y] + 1);
        build(x, y);
        for (int z: tree[x]) {
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
} lca;

bool sf(int x, int y) {
    return lca.depth[x] > lca.depth[y];
}


void process() {
    int m;
    cin >> m;
    vi t(m);
    for (int &x: t)cin >> x, x --;
    sort(t.begin(), t.end(), sf);

    int a = -1, b = -1;
    for (int i = 0; i < m; i++) {
        int x = t[i];
        int dep = lca.depth[x];
        if (a == -1)a = x;
        else if (b == -1) {
            a = lca.up_to(a, dep);
            if (a != x) b = x;
        } else {
            int c = lca.lca(a, b);
            if( lca.depth[c] > dep) {
                cout <<"NO\n";
                return;
            }else if(lca.depth[c] == dep) {
                if(c != x || i != m -1) {
                    cout <<"NO\n";
                    return;
                }
            }else {
                a = lca.up_to(a, dep);
                b = lca.up_to(b, dep);
                if(a != x && b != x) {
                    cout <<"NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}
void solve() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        x--, y--;
        v[x].pb(y);
        v[y].pb(x);
    }

    lca.init(n, v);

    cin >> q;
    while (q--)
        process();

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
