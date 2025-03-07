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
    int n;
    cin >> n;

    map<int, int> idx, value;
    vi v(n);
    for (int &x: v)cin >> x;
    vi t = v;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (int i = 0; i < t.size(); i++)idx[t[i]] = i;
    for (int i = 0; i < n; i++)value[idx[v[i]]] = i;

    int m = t.size();
    IndexTree<MinMaxNode> tr(m);
    for (int i = 0; i < m; i++)tr.up(i, MinMaxNode(value[i], value[i]));

    for(int i=0;i<n;i++){
        int x = idx[v[i]];
        MinMaxNode t = tr.read(0, x - 1);
        cout << max(-1ll, t.max_v - i - 1) << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
