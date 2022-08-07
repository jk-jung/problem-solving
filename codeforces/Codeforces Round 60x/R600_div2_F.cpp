/*
 * Idea
 * - 어떤 노드 x에 도착했다면, 무조건 가장 가까운 central에 갔다가 오는 것이 유리하다.
 * - 이렇게 하면 문제를 경로에 있는 edge중 최대값을 찾는 문제로 변환 가능
 * - 그 후에 union-find를 이용해서 각각의 query를 해결 가능.
 * - 여기서 효율적인 처리를 위해 token을 이용
 */

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

int n, m, k, Q;
vector<pi> v[100005];
vector<tuple<ll, int, int>> edges;
ll dis[100005];
ll r[300005];


void dij() {
    memset(dis, 63, sizeof(dis));
    priority_queue<pair<ll, int>> q;
    for (int i = 1; i <= k; i++) q.push({0ll, i}), dis[i] = 0;
    while (!q.empty()) {
        auto [d, x] = q.top();
        d = -d;
        q.pop();
        if (d > dis[x]) continue;

        for (auto [y, w]: v[x]) {
            ll nt = d + w;
            if (nt < dis[y]) {
                dis[y] = nt;
                q.push({-nt, y});
            }
        }
    }
}

class DisjointSetUnion {
public:
    vector<int> p, size;
    vector<set<int>> tok;

    DisjointSetUnion(int _n = 0) { init(_n); }

    void init(int _n) {
        p.resize(_n), iota(p.begin(), p.end(), 0);
        size.resize(_n), fill(size.begin(), size.end(), 1);
        tok.resize(_n);
    }

    int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

    void unite(int x, int y, ll weight) {
        x = find(x), y = find(y);
        if (size[x] > size[y]) swap(x, y);
        p[x] = p[y], size[y] += size[x];

        for (int t: tok[x]) {
            if (tok[y].count(t))r[t] = weight;
            else tok[y].insert(t);
        }
        tok[x].clear();
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
};

void solve() {
    cin >> n >> m >> k >> Q;
    for (int i = 0, x, y, w; i < m; i++) {
        cin >> x >> y >> w;
        v[x].pb({y, w});
        v[y].pb({x, w});
        edges.pb({w, x, y});
    }

    DisjointSetUnion dsu(n + 1);
    for (int i = 0, x, y; i < Q; i++) {
        cin >> x >> y;
        dsu.tok[x].insert(i);
        dsu.tok[y].insert(i);
    }

    dij();

    for (auto &[w, x, y]: edges)w += dis[x] + dis[y];
    sort(edges.begin(), edges.end());

    for (auto &[w, x, y]: edges) {
        if (!dsu.is_same_set(x, y)) dsu.unite(x, y, w);
    }

    for (int i = 0; i < Q; i++) cout << r[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
