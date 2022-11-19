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
        d[x] += v;
        x /= 2;
        while (x) d[x] = min(d[x * 2], d[x * 2 + 1]), x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 1 << 30;
        while (s <= e) {
            if ((s & 1) == 1) r = min(r, d[s++]);
            if ((e & 1) == 0) r = min(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r == (1 << 30) ? 0 : r;
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
    int n, m;
    cin >> n >> m;

    IndexTree xx(n + 1), yy(n + 1);
    while (m--) {
        int op, a, b, c, d;
        cin >> op >> a >> b;
        if (op == 3) {
            cin >> c >> d;

            bool x = xx.read(a, c) > 0;
            bool y = yy.read(b, d) > 0;
            cout << (x || y ? "Yes" : "No") << endl;
        } else {
            xx.up(a, op == 1 ? 1 : -1);
            yy.up(b, op == 1 ? 1 : -1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
