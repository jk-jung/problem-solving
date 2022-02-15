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


class IndexTree {
public:
    int n, size;
    vector<int> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        d[x] = v;
        x >>= 1;
        while (x) d[x] = max(d[x * 2], d[x * 2 + 1]), x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r = max(r, d[s++]);
            if ((e & 1) == 0) r = max(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int find(int t) {
        int x = 1;
        while (x < size) {
            if (d[x * 2] == t) x = x * 2;
            else x = x * 2 + 1;
        }
        return x - size;
    }
};

void solve() {
    int n;
    cin >> n;
    vi v(n), nt(n), pos(n + 2, n);
    for (int &x: v)cin >> x;

    IndexTree tre(n + 2);
    for (int i = n - 1; i >= 0; i--) {
        nt[i] = pos[v[i]];
        pos[v[i]] = i;
    }
    for (int i = 0; i <= n + 1; i++)tre.up(i, pos[i]);

    vi r;
    int s = 0;
    while (true) {
        int val = tre.find(n);
        int idx = tre.read(0, val - 1);
        if (val == 0)idx = s;
        while (s <= idx) {
            tre.up(v[s], nt[s]);
            s++;
        }
        r.pb(val);

        if (s == n)break;
    }

    cout << r.size() << '\n';
    for (int x: r)cout << x << " ";
    cout << '\n';
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
