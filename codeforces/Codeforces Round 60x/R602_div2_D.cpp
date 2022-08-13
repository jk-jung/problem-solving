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

class IndexTree {
public:
    int n, size;
    vector<int> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        if (_n <= 0)return;
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        x += size;
        while (x) d[x] += v, x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s++];
            if ((e & 1) == 0) r += d[e--];
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int kth(int k) {
        int x = 1;
        while (x < size) {
            if (d[x * 2] < k) k -= d[x * 2], x = x * 2 + 1;
            else x *= 2;
        }
        return x - size;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    vi real(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F, v[i].S = i;
        real[i] = v[i].F;
        v[i].F = -v[i].F;
    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    vector<pair<pi, int>> q(m);
    vi r(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].F.F >> q[i].F.S;
        q[i].S = i;
    }
    sort(q.begin(), q.end());

    IndexTree tre(n);
    int pos = 0;
    for (auto [t, idx]: q) {
        while (pos < t.F)
            tre.up(v[pos++].S, 1);

        int i = tre.kth(t.S);
        r[idx] = real[i];
    }

    for (int x: r)cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
