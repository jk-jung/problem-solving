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
    int L, R, vl, vr;
    bool ck;

    Node() {
        M = -1;
    }
};

class SegmentTree {
public:
    vector<Node> d;
    int max_n;

    void init(int _max_n) {
        max_n = _max_n;
        int size = 1;
        for (; size < max_n; size *= 2);
        d.resize(size * 2 + 5);
    }

    void up(int x, int v) {
        up(x, v, 0, 0, max_n);
    }

    void up(int x, int v, int k, int l, int r) {
        if (r < l || r < x || x < l) return;
        if (l == x && r == x) {
            d[k].L = d[k].R = 1;
            d[k].M = 0;
            d[k].ck = true;
            d[k].vl = d[k].vr = v;
        } else {
            int m = (l + r) / 2;
            up(x, v, k * 2 + 1, l, m);
            up(x, v, k * 2 + 2, m + 1, r);
            d[k] = merge(d[k * 2 + 1], d[k * 2 + 2]);
        }
    }

    ll cnt(ll x) { return x * (x + 1) / 2; }

    Node merge(Node &a, Node &b) {
        if (a.M == -1)return b;
        if (b.M == -1)return a;
        Node r;
        r.ck = false;
        r.vl = a.vl;
        r.vr = b.vr;

        if (a.ck && b.ck) {
            if (a.vr <= b.vl) {
                r.ck = true;
                r.L = r.R = a.L + b.R;
                r.M = 0;
            } else {
                r.L = a.L;
                r.R = b.R;
                r.M = 0;
            }
        } else if (a.ck) {
            r.R = b.R;
            if (a.vr <= b.vl) {
                r.L = a.L + b.L;
                r.M = b.M;
            } else {
                r.L = a.L;
                r.M = b.M + cnt(b.L);
            }
        } else if (b.ck) {
            r.L = a.L;
            if (a.vr <= b.vl) {
                r.R = a.R + b.R;
                r.M = a.M;
            } else {
                r.R = b.R;
                r.M = a.M + cnt(a.R);
            }
        } else {
            r.L = a.L;
            r.R = b.R;
            r.M = a.M + b.M;
            if (a.vr <= b.vl) r.M += cnt(a.R + b.L);
            else r.M += cnt(a.R) + cnt(b.L);
        }
        return r;
    }

    ll read(int s, int e) {
        Node r = read(s, e, 0, 0, max_n);
        if (r.ck) return cnt(r.L);
        return r.M + cnt(r.L) + cnt(r.R);
    }

    Node read(int s, int e, int k, int l, int r) {
        if (r < l || r < s || e < l) return {};
        if (s <= l && r <= e) return d[k];
        else {
            int m = (l + r) / 2;
            Node a = read(s, e, k * 2 + 1, l, m);
            Node b = read(s, e, k * 2 + 2, m + 1, r);
            return merge(a, b);
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
