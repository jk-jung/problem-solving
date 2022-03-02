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
};

int n, m;

struct Edge {
    int s, e, w;

    Edge(int _s = 0, int _e = 0, int _w = 0) : s(_s), e(_e), w(_w) {}
};

set<int> full;
set<pi> used;
vector<Edge> ed_org, ed_full, ed, ed0;
int deg[200005];
int ok[200005];
int xo = 0;
int idx = 0;

bool sf(Edge &a, Edge &b) {
    return a.w < b.w;
}


ll calc(int ig) {
    ll r = ig == -1 ? xo : 0;
    DisjointSetUnion dsu(n + 1);
    for (int i = 0; i < ed0.size(); i++) {
        if (i == ig)continue;

        auto x = ed0[i];
        int s = dsu.find(x.s);
        int e = dsu.find(x.e);
        if (s == e)continue;
        dsu.unite(s, e);
    }

    for (auto x: ed_org) {
        int s = dsu.find(x.s);
        int e = dsu.find(x.e);
        if (s == e)continue;
        r += x.w;
        dsu.unite(s, e);
    }
    return r;
}

void solve() {
    cin >> n >> m;
    ed_org.resize(m);

    for (auto &x: ed_org) {
        cin >> x.s >> x.e >> x.w;
        if (x.s > x.e) swap(x.s, x.e);
        deg[x.s]++;
        deg[x.e]++;
        used.insert({x.s, x.e});
        xo ^= x.w;
    }


    for (int i = 1; i <= n; i++) {
        deg[i]++;
        if (deg[i] == n) full.insert(i);
    }

    for (int i = 0; i < m; i++) {
        auto x = ed_org[i];
        if (full.count(x.s) || full.count(x.e)) ed_full.pb(x);
        else ed.pb(x);
    }

    ll rest = (ll) n * (n - 1) / 2 - m;

//    rest = -1;
    if (rest <= n * 10) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (used.count({i, j}))continue;
                ed0.pb(Edge(i, j, idx++));
            }
        }
    } else {
        int mm = n - (int) full.size();
        set<int> ss;
        for (int i = 1; i <= n; i++)if (deg[i] != n)ss.insert(i);
        for (int i = 1; i <= n; i++) {
            if (deg[i] == n)continue;
            ss.erase(i);
            vi er;
            for (int j: ss) {
                if (used.count({i, j}))continue;
                er.pb(j);
                ed0.pb(Edge(i, j, idx++));
            }
            if (ed0.size() == mm - 1) break;
            for (int j: er)ss.erase(j);
        }
        idx = 0;
        xo = 0;
    }

    sort(ed_org.begin(), ed_org.end(), sf);
    ll t = 1ll << 60;
    for (int i = -1; i < idx; i++) {
        t = min(t, calc(i));
    }
    if (t == 1ll << 60) t = 0;
    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}