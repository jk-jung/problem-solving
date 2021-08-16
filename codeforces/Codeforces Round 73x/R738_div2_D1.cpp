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

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DisjointSetUnion d1(n + 1), d2(n + 1);

    int s, e;
    for (int i = 0; i < m1; i++) {
        cin >> s >> e;
        d1.unite(s, e);
    }

    for (int i = 0; i < m2; i++) {
        cin >> s >> e;
        d2.unite(s, e);
    }

    vector<pi> r;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (d1.is_same_set(i, j))continue;
            if (d2.is_same_set(i, j))continue;

            r.pb({i, j});
            d1.unite(i, j);
            d2.unite(i, j);
        }
    cout << r.size() << endl;
    for(int i=0;i<r.size();i++){
        cout << r[i].F <<" " <<r[i].S << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
