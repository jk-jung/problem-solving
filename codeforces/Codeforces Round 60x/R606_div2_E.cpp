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
        if (is_same_set(x, y)) return;
        x = find(x), y = find(y);
        if (size[x] > size[y]) swap(x, y);
        p[x] = p[y], size[y] += size[x];
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
};

int n, m, A, B;
vi v[200005];

void dfs(int x, int no, DisjointSetUnion &dsu, vi &ck) {
    ck[x] = 1;
    for (int y: v[x]) {
        if (y != no && x != no)dsu.unite(x, y);
        if (!ck[y])dfs(y, no, dsu, ck);
    }
}

void solve() {
    cin >> n >> m >> A >> B;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    DisjointSetUnion dsu_a(n + 1), dsu_b(n + 1);

    vi ck_a(n + 1), ck_b(n + 1);
    dfs(A, A, dsu_a, ck_a);
    dfs(B, B, dsu_b, ck_b);

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (i == A || dsu_a.find(i) != i || dsu_a.find(i) == dsu_a.find(B))continue;
        a += dsu_a.get_size(i);
    }
    for (int i = 1; i <= n; i++) {
        if (i == B || dsu_b.find(i) != i || dsu_b.find(i) == dsu_b.find(A))continue;
        b += dsu_b.get_size(i);
    }

    cout << (ll) a * b << endl;
    for (int i = 1; i <= n; i++)v[i].clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}