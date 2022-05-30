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

    IndexTree(int _n = 1) {
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
        d[x] = max(d[x], v);
        x /= 2;
        while (x) d[x] = max(d[x * 2], d[x * 2 + 1]), x >>= 1;
    }

    int read(int s, int e) {
        if (e < s) return 0;
        s += size, e += size;
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r = max(r, d[s++]);
            if ((e & 1) == 0) r = max(r, d[e--]);
            s >>= 1, e >>= 1;
        }
        return r;
    }
};

bool sf(pi &a, pi &b) {
    if (a.S == b.S)return a.F > b.F;
    return a.S < b.S;
}

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    vi s(n), e;
    for (auto &[x, y]: v)cin >> x >> y;
    for (int i = 0; i < n; i++)s[i] = v[i].F, e.pb(v[i].F), e.pb(v[i].S);

    sort(v.begin(), v.end(), sf);
    sort(s.begin(), s.end()), s.erase(unique(s.begin(), s.end()), s.end());
    sort(e.begin(), e.end()), e.erase(unique(e.begin(), e.end()), e.end());

    vector<vi> d(n, vi(s.size()));
    vector<IndexTree> tre(s.size(), e.size());
    IndexTree tre2(s.size());

    int r = 0;
    for (int i = 0; i < n; i++) {
        int s_i = lower_bound(s.begin(), s.end(), v[i].F) - s.begin();
        int es_i = lower_bound(e.begin(), e.end(), v[i].F) - e.begin();
        int ee_i = lower_bound(e.begin(), e.end(), v[i].S) - e.begin();

        int x = 1;
        for (int j = s_i; j < s.size() && s[j] <= v[i].S; j++) {
            x = max(x, tre[j].read(0, ee_i) + 1);
        }

        for (int j = 0; j <= s_i; j++) {
            int tmp = tre[j].read(0, es_i - 1) + x;
            d[i][j] = max(d[i][j], tmp);
            r = max(r, d[i][j]);

            tre[j].up(ee_i, tmp);
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
