#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n, m;
vector<pair<int, pi>> v;

class SegmentTree {
public:
    vector<int> sum, cnt;
    int max_n;

    void init(int _max_n) {
        max_n = _max_n;
        int size = 1;
        for (; size < max_n; size *= 2);
        sum.clear(), sum.resize(size * 2 + 5);
        cnt.clear(), cnt.resize(size * 2 + 5);
    }

    void up(int s, int e, int v) {
        up(s, e, v, 0, 0, max_n);
    }

    void up(int s, int e, int v, int k, int l, int r) {
        if (r < l || r < s || e < l) return;
        if (s <= l && r <= e) cnt[k] += v;
        else {
            int m = (l + r) / 2;
            up(s, e, v, k * 2 + 1, l, m);
            up(s, e, v, k * 2 + 2, m + 1, r);
        }
        update(k, l, r);
    }

    void update(int k, int l, int r) {
        sum[k] = 0;
        if (cnt[k]) sum[k] = r - l + 1;
        else if (l != r) sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
    }
};

void solve() {
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].S.F >> v[i].S.S >> v[i].F;
        v[i].S.S--;
    }
    sort(v.begin(), v.end());

    int r = 1 << 30, last = 0;
    SegmentTree seg;
    seg.init(m);

    for (int i = 0; i < n;) {
        int x = v[i].F;
        while (i < n && v[i].F == x) {
            seg.up(v[i].S.F, v[i].S.S, 1);
            i++;
        }

        while (seg.sum[0] == m - 1) {
            r = min(r, x - v[last].F);
            seg.up(v[last].S.F, v[last].S.S, -1);
            last++;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}



