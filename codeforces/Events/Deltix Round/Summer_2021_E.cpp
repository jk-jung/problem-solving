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

template<typename Node>
class IndexTree {
public:
    int n, size;
    vector<Node> d;

    IndexTree(int _n) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        size = 1 << (32 - __builtin_clz(n));
        d.resize(size * 2 + 5);
    }

    void up(int x, Node v) {
        x += size;
        while (x) d[x].up(v), x >>= 1;
    }

    Node read(int s, int e) {
        s += size, e += size;
        Node r;
        while (s <= e) {
            if ((s & 1) == 1) r.up(d[s++]);
            if ((e & 1) == 0) r.up(d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }
};

struct MinMaxNode {
    ll min_v, max_v;

    MinMaxNode(ll a = (1ll << 62), ll b = -(1ll << 62)) {
        min_v = a;
        max_v = b;
    }

    void up(MinMaxNode &t) {
        min_v = min(min_v, t.min_v);
        max_v = max(max_v, t.max_v);
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vi v(n);
    vector<ll> ss(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v[i] = k - v[i];
    }
    IndexTree<MinMaxNode> tre(n);

    for (int i = 0; i < n; i++) {
        ss[i] = v[i] + (i > 0 ? ss[i - 1] : 0);
        tre.up(i, MinMaxNode(ss[i], ss[i]));
    }

    while (q--) {
        int s, e;
        cin >> s >> e;
        s--, e--;
        ll base = s == 0 ? 0 : ss[s - 1];

        auto [b, a] = tre.read(s, e);

        ll r = 0;
        if (b < base || ss[e] - base != 0) r = -1;
        else r = a - base;

        cout << r << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
