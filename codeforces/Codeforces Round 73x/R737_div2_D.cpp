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
    vector<pi> vv, vp;
    int max_n;

    void init(int _max_n) {
        max_n = _max_n;
        int size = 1;
        for (; size < max_n; size *= 2);
        vv.clear(), vv.resize(size * 2 + 5);
        vp.clear(), vp.resize(size * 2 + 5);
    }

    void up(int s, int e, pi v) {
        up(s, e, v, 0, 0, max_n);
    }

    void up(int s, int e, pi v, int k, int l, int r) {
        push_down(k, l, r);
        if (r < l || r < s || e < l) return;
        if (s <= l && r <= e) {
            vv[k] = max(vv[k], v);
            vp[k] = max(vp[k], v);
        } else {
            int m = (l + r) / 2;
            up(s, e, v, k * 2 + 1, l, m);
            up(s, e, v, k * 2 + 2, m + 1, r);
        }
        update(k, l, r);
    }

    void update(int k, int l, int r) {
        if (l != r) {
            vv[k] = max(vv[k], vv[k * 2 + 1]);
            vv[k] = max(vv[k], vv[k * 2 + 2]);
        }
    }

    void push_down(int k, int l, int r) {
        if (l != r) {
            int ll = k * 2 + 1, rr = k * 2 + 2;
            vv[ll] = max(vv[ll], vp[k]);
            vv[rr] = max(vv[rr], vp[k]);
            vp[ll] = max(vp[ll], vp[k]);
            vp[rr] = max(vp[rr], vp[k]);
        }
        vp[k] = {0, 0};
    }

    pi read(int s, int e) {
        return read(s, e, 0, 0, max_n);
    }

    pi read(int s, int e, int k, int l, int r) {
        push_down(k, l, r);
        pi rst = {0, 0};
        if (r < l || r < s || e < l) return rst;
        if (s <= l && r <= e) rst = max(rst, vv[k]);
        else {
            int m = (l + r) / 2;
            rst = max(rst, read(s, e, k * 2 + 1, l, m));
            rst = max(rst, read(s, e, k * 2 + 2, m + 1, r));
        }
        return rst;
    }
};

int n, m;
vector<int> L[300005];
vector<int> R[300005];
map<int, int> ck, ck2;
int from[300005];
int d[300005];
int used[300005];


void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        L[a].pb(b), ck2[b] = 1;
        R[a].pb(c), ck2[c] = 1;
    }

    int c = 0;
    for (auto it : ck2) ck[it.F] = c++;

    SegmentTree seg;
    seg.init(ck.size());

    pi rr = {0, 0};
    for (int i = 1; i <= n; i++) {
        pi r = {0, 0};
        for (int k = 0; k < L[i].size(); k++) {
            int s = ck[L[i][k]];
            int e = ck[R[i][k]];
            r = max(r, seg.read(s, e));
//            cout << seg.read(ck[3], ck[3]).F << endl;
        }

        d[i] = r.F + 1;
        from[i] = r.S;
        rr = max(rr, {d[i], i});

        for (int k = 0; k < L[i].size(); k++) {
            int s = ck[L[i][k]];
            int e = ck[R[i][k]];
            seg.up(s, e, {d[i], i});
        }
//        cout << i << " d[i]: " << d[i] << "  / from[i]: " << from[i] << endl;
    }

    vi rst;
    int k = rr.S;
    while(k) {
        used[k] = 1;
        k = from[k];
    }
    for(int i=1;i<=n;i++)if(!used[i])rst.pb(i);
    cout << rst.size() << endl;
    for(int i=0;i<rst.size();i++)cout << rst[i] <<" " ;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
