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


int can[500005];

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

        int c = 1 << 30;
        if (can[x]) c = min(c, can[x]);
        if (can[y]) c = min(c, can[y]);
        if (c == (1 << 30)) c = 0;
        can[y] = c;
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
} dsu(500005);

int n, m;


void solve() {
    cin >> n >> m;
    vi r;
    for (int i = 1; i <= n; i++) {
        int k, a, b;
        cin >> k;
        if (k == 1) {
            cin >> a;
            a = dsu.find(a);
            if (!can[a]) can[a] = i;
        } else {
            cin >> a >> b;
            a = dsu.find(a);
            b = dsu.find(b);
            if (a != b && !(can[a] && can[b])) {
                dsu.unite(a, b);
                r.pb(i);
            }
        }
    }
    for (int i = 1; i <= m; i++)if (dsu.find(i) == i && can[i])r.pb(can[i]);
    sort(r.begin(), r.end());

    int v = 1;
    for (int _: r)v = v * 2 % 1000000007;
    cout << v << " " << r.size() << endl;
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
