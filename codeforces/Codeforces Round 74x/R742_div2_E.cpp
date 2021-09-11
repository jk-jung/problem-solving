#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
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


struct Node {
    ll M;
    int L, R, vl, vr, len;

    Node() : vl(1<<30), vr(-(1<<30)), M(0), len(0), L(0), R(0) {}
    Node(int v) : vl(v), vr(v), L(1), R(1), M(1), len(1) {}

    Node operator+(const Node &t) const {
        Node r;
        bool disconnected = vr > t.vl;
        r.len = len + t.len;
        r.vl = vl, r.vr = t.vr;
        r.L = (L < len || disconnected) ? L : L + t.L;
        r.R = (t.R < t.len || disconnected) ? t.R : R + t.R;
        r.M = M + t.M + (disconnected ? 0 : (ll) R * t.L);
        return r;
    }
};

class SegmentTree {
public:
    vector<Node> d;
    int max_n, size;

    void init(int _max_n) {
        max_n = _max_n;
        for (size = 1; size < max_n; size *= 2);
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        up(x, v, 0, 0, max_n);
    }

    void up(int x, int v, int k, int l, int r) {
        if (r < l || r < x || x < l) return;
        if (l == x && r == x) {
            d[k] = Node(v);
        } else {
            int m = (l + r) / 2;
            up(x, v, k * 2 + 1, l, m);
            up(x, v, k * 2 + 2, m + 1, r);
            d[k] = d[k * 2 + 1] + d[k * 2 + 2];
        }
    }

    ll read(int s, int e) {
        return read(s, e, 0, 0, max_n).M;
    }

    Node read(int s, int e, int k, int l, int r) {
        if (r < l || r < s || e < l) return {};
        if (s <= l && r <= e) return d[k];
        else {
            int m = (l + r) / 2;
            return read(s, e, k * 2 + 1, l, m) + read(s, e, k * 2 + 2, m + 1, r);
        }
    }
} tre;

void solve() {
    int n, q;
    cin >> n >> q;
    tre.init(n + 1);

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        tre.up(i, v);
    }

    while (q--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            tre.up(a, b);
        } else {
            cout << tre.read(a, b) << '\n';
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
