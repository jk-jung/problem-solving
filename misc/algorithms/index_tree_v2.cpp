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

