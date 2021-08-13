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


class SegmentTree {
public:
    vector<int> vv, vp;
    int max_n;

    void init(int _max_n) {
        max_n = _max_n;
        int size = 1;
        for (; size < max_n; size *= 2);
        vv.clear(), vv.resize(size * 2 + 5);
        vp.clear(), vp.resize(size * 2 + 5);
    }

    void up(int s, int e, int v) {
        up(s, e, v, 0, 0, max_n);
    }

    void up(int s, int e, int v, int k, int l, int r) {
        push_down(k, l, r);
        if (r < l || r < s || e < l) return;
        if (s <= l && r <= e) {
            vv[k] += v;
            vp[k] += v;
        } else {
            int m = (l + r) / 2;
            up(s, e, v, k * 2 + 1, l, m);
            up(s, e, v, k * 2 + 2, m + 1, r);
        }
        update(k, l, r);
    }

    void update(int k, int l, int r) {
        if (l != r) {
            vv[k] += vv[k * 2 + 1];
            vv[k] += vv[k * 2 + 2];
        }
    }

    void push_down(int k, int l, int r) {
        if (l != r) {
            int ll = k * 2 + 1, rr = k * 2 + 2;
            vv[ll] += vp[k];
            vv[rr] += vp[k];
            vp[ll] += vp[k];
            vp[rr] += vp[k];
        }
        vp[k] = 0;
    }

    int read(int s, int e) {
        return read(s, e, 0, 0, max_n);
    }

    int read(int s, int e, int k, int l, int r) {
        push_down(k, l, r);
        int rst = 0;
        if (r < l || r < s || e < l) return rst;
        if (s <= l && r <= e) rst += vv[k];
        else {
            int m = (l + r) / 2;
            rst = max(rst, read(s, e, k * 2 + 1, l, m));
            rst = max(rst, read(s, e, k * 2 + 2, m + 1, r));
        }
        return rst;
    }
};

int n, ck, r;
vector<int> v1[300005];
vector<int> v2[300005];
int in[300005], out[300005];
SegmentTree seg;

void dfs1(int x) {
    in[x] = ck++;
    for (int y : v2[x]) dfs1(y);
    out[x] = ck++;
}

void dfs2(int x, int cnt) {
    int t = seg.read(in[x], in[x]);
    if(t) seg.up(in[t], out[t], -t), cnt --;
    seg.up(in[x], out[x], x), cnt ++;

    r = max(r, cnt);

    for (int y : v1[x]) dfs2(y, cnt);

    seg.up(in[x], out[x], -x), cnt --;
    if(t) seg.up(in[t], out[t], t), cnt ++;
}

void solve() {
    cin >> n;

    int x;
    for (int i = 2; i <= n; i++) cin >> x, v1[x].pb(i);
    for (int i = 2; i <= n; i++) cin >> x, v2[x].pb(i);

    seg.init(n * 2 + 1);

    ck = 0, r = 0;
    dfs1(1);
    dfs2(1, 0);

    cout << r << endl;

    for (int i = 1; i <= n; i++) v1[i].clear(), v2[i].clear();
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
