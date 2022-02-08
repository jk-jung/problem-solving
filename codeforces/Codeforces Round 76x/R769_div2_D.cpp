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

    IndexTree(int _n = 0) {
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
        while (x) d[x] = gcd(d[x * 2], d[x * 2 + 1]), x >>= 1;
    }

    int read(int s, int e) {
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r = gcd(r, d[s++]);
            if ((e & 1) == 0) r = gcd(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }
};

int n;
IndexTree tre;

bool check(int s, int ee) {
    int e = ee;
    while (s <= e) {
        int m = (s + e) / 2;

        int l = ee - m + 1;
        int g = tre.read(m, ee);

        if (g == l) return true;
        else if (g < l) s = m + 1;
        else e = m - 1;
    }
    return false;
}

void solve() {
    cin >> n;
    tre.init(n);

    int last = 0, r = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        tre.up(i, x);

        if (x == 1 || check(last, i)) r++, last = i + 1;
        cout << r << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
