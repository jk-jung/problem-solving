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

int n, m;
vi v[100005];
int s[100005];
int ord[100005], O;
vi st;
set<pi> rev;

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
        if(s[y] > s[x])swap(x, y);
        p[x] = p[y], size[y] += size[x];
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
};


DisjointSetUnion du(100005);


void dfs(int x, int y = -1, int dep = 1) {
    if (s[x]) {
        if (!du.is_same_set(x, y)) {
            rev.insert(mp(y, x));
            while(true) {
                int p = du.find(x);
                y = du.find(y);
                if(y == p)break;
                du.unite(y, p);
                y = st[s[y] - 2];
            }
        }
        return;
    }
    s[x] = dep;
    ord[x] = ++O;
    st.pb(x);
    for (int z: v[x]) {
        if (z != y)dfs(z, x, dep + 1);
    }

    st.pop_back();
}

void solve() {
    cin >> n >> m;
    vector<pi> r;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
        r.pb(mp(x, y));
    }
    dfs(1);
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(du.find(i));

    if (s.size() == 1) {
        for (auto [x, y]: r) {
            if (rev.count(mp(x, y))) cout << x << " " << y << endl;
            else if (rev.count(mp(y, x)))cout << y << " " << x << endl;
            else {
                if (ord[x] > ord[y])swap(x, y);
                cout << x << " " << y << endl;
            }
        }
    } else cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
