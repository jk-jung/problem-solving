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

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vi a(26, -1), b(26, -1);
    DisjointSetUnion dsu(26);

    // a -> b
    string r;
    for (char x: s) {
        int t = x - 'a';
        if (a[t] == -1) {
            for (int i = 0; i < 26; i++) {
                bool ok = false;
                if (t != i && b[i] == -1) {
                    if (dsu.is_same_set(i, t)) {
                        if (dsu.get_size(i) == 26) ok = true;
                    } else {
                        ok = true;
                    }
                }
                if (ok) {
                    a[t] = i;
                    b[i] = t;
                    dsu.unite(t, i);
                    break;
                }
            }
        }
        r += char(a[t] + 'a');
    }
    cout << r << endl;
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
