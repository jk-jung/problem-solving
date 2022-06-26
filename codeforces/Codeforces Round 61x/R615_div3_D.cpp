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
        d[x]++;
        x /= 2;
        while (x) d[x] = min(d[x * 2 + 1], d[x * 2]), x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 1 << 30;
        while (s <= e) {
            if ((s & 1) == 1) r = min(r, d[s++]);
            if ((e & 1) == 0) r = min(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }

    int find(int k) {
        int x = 1;
        while (x < size) {
            if (d[x * 2] <= k) x = x * 2;
            else x = x * 2 + 1;
        }
        return x - size;
    }
};

void solve() {
    int q, x, k;
    cin >> q >> x;

    IndexTree tre(x);
    while (q--) {
        cin >> k;
        tre.up(k % x, 1);
        int y = tre.read(0, x - 1);
        cout << y * x + tre.find(y) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
