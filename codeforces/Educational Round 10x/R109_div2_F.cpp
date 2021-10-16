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


ll d[55][55];
int fr[55][55];
int eL[55], eR[55];


class BipartiteMatching {
public:
    int n, m, CK;
    vi L, R, ck;
    vector<vi> v;

    void init(int _n, int _m, vector<vi> _v) {
        n = _n, m = _m, v = _v;
    }

    int match() {
        L.clear(), L.resize(n, -1);
        R.clear(), R.resize(m, -1);
        ck.clear(), ck.resize(n, -1);
        CK = 1;

        int r = 0;
        for (int i = 0; i < n; i++, CK++)r += find(i);
        return r;
    }

    bool find(int x) {
        if (eL[x]) return false;
        if (ck[x] == CK) return false;
        ck[x] = CK;

        for (int y: v[x]) {
            if (eR[y])continue;
            if (R[y] == -1 || find(R[y])) {
                R[y] = x;
                L[x] = y;
                return true;
            }
        }
        return false;
    }
} bm;

int n, m, k;

int remove() {
    int c = bm.match() - 1;
    for (int i = 0; i < n; i++) {
        if (!eL[i]) {
            eL[i] = 1;
            if (bm.match() == c) return i + 1;
            eL[i] = 0;
        }
        if (!eR[i]) {
            eR[i] = 1;
            if (bm.match() == c) return -i - 1;
            eR[i] = 0;
        }
    }

    return -1000;
}

void solve() {
    memset(d, 200, sizeof(d));

    cin >> n >> m >> k;
    vector<vi> v(n);
    while (m--) {
        int s, e;
        cin >> s >> e;
        v[s - 1].pb(e - 1);
    }

    bm.init(n, n, v);
    int c = n - bm.match();

    d[0][c] = 0;
    ll r = d[0][0];
    int idx = -1;
    for (int i = 1; i <= k; i++) {
        ll x, y;
        cin >> x >> y;
        for (int j = i + 1; j <= n; j++) {
            for (int l = 1; l <= j; l++) {
                ll t = max(0ll, x - (j - l) * y);
                if (d[i][j] < d[i - 1][l] + t) {
                    d[i][j] = d[i - 1][l] + t;
                    fr[i][j] = l;
                }
            }
            if (i == k && r < d[i][j]) r = d[i][j], idx = j;
        }
    }

    vi rst;
    for (int row = k; row; idx = fr[row--][idx]) {
        rst.pb(0);
        for (int i = fr[row][idx]; i < idx; i++) rst.pb(remove());
    }
    reverse(rst.begin(), rst.end());

    cout << rst.size() << "\n";
    for (int x: rst) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
