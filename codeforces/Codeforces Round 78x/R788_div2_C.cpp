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
        if(x == y)return;
        if (size[x] > size[y]) swap(x, y);
        p[x] = p[y], size[y] += size[x];
    }

    int get_size(int x) { return size[find(x)]; }

    bool is_same_set(int x, int y) { return find(x) == find(y); }
};


void solve() {
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1), c(n), ck(n, 2);
    for (int i = 0, x; i < n; i++)cin >> x, a[x] = i;
    for (int i = 0, x; i < n; i++)cin >> x, b[x] = i;
    for (int &y: c)cin >> y;

    DisjointSetUnion dsu(n + 1);
    for (int i = 1; i <= n; i++)dsu.unite(a[i], b[i]);
    for (int k: c) {
        if (k) {
            int x = dsu.find(a[k]);
            ck[x] = 1;
        }
    }
    int r = 1;
    for (int i = 0; i < n; i++)
        if (dsu.find(i) == i) {
            if (dsu.size[i] == 1)ck[i] = 1;
            r = (r * ck[i]) % 1000000007;
        }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
