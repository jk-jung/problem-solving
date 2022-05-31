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
        if (s > e) return 0;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s++];
            if ((e & 1) == 0) r += d[e--];
            s >>= 1, e >>= 1;
        }
        return r;
    }
};

void solve() {
    int n;
    cin >> n;
    vi v(n), cc;
    for (int &x: v)cin >> x;

    ll r = 0;
    IndexTree tre(n + 1);
    for (int x: v)tre.up(x, 1);
    for (int x: v) {
        tre.up(x, -1);
        cc.pb(tre.read(1, x));
    }

    for (int i = 0; i < n; i++) {
        IndexTree tre2(n + 1);

        ll c = 0;
        for (int j = i + 1; j < n; j++) {
            c -= tre2.read(v[j], n);
            tre2.up(v[j], 1);
            if (v[i] < v[j]) r += c;
            c += cc[j];
        }
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
