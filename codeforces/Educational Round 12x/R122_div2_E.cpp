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
typedef vector<ll> vi;

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

struct Data {
    ll s, e, w, i, ow;
};

bool sf(Data &a, Data &b) {
    if (a.w == b.w) return a.i < b.i;
    return a.w < b.w;
}

int n, m;
vector<Data> v;
vi q, w;
vi rr, up, down;

void calc(ll x) {
    for (int i = 0; i < m; i++)v[i].w = ab(v[i].ow - x);
    sort(v.begin(), v.end(), sf);

    DisjointSetUnion dsu(n);
    ll r = 0, uu = 0, dd = 0;
    for (int i = 0; i < m; i++) {
        int s = dsu.find(v[i].s);
        int e = dsu.find(v[i].e);
        if (s == e) continue;

        dsu.unite(s, e);
        r += v[i].w;
        if (v[i].ow <= x) uu++;
        else dd++;
    }
    rr.pb(r);
    up.pb(uu);
    down.pb(dd);
}

void solve() {
    cin >> n >> m;
    v.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> v[i].s >> v[i].e >> v[i].w;
        v[i].s--, v[i].e--;
        v[i].i = i;
        v[i].ow = v[i].w;
    }
    sort(v.begin(), v.end(), sf);

    w.pb(0);
    w.pb(100000000);
    for (int i = 0; i < m; i++) {
        w.pb(v[i].w);
        for (int j = i + 1; j < m; j++) {
            int dif = (v[j].w - v[i].w) / 2;
            w.pb(v[i].w + dif);
            w.pb(v[i].w + dif - 1);
            w.pb(v[i].w + dif + 1);
        }
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());

    for (ll x: w) calc(x);

    ll p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    q.resize(k);
    for (int i = 0; i < p; i++)cin >> q[i];
    for (int i = p; i < k; i++)q[i] = ((ll) q[i - 1] * a + b) % c;

    sort(q.begin(), q.end());

    ll r = 0, pos = 0;
    for (ll x: q) {
        while (w[pos] <= x)pos++;
        pos--;
        ll offset = x - w[pos];
        ll t = rr[pos] + up[pos] * offset - down[pos] * offset;
        r ^= t;
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
