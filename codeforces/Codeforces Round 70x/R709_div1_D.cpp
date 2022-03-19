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
        int r = 0;
        while (s <= e) {
            if ((s & 1) == 1) r += d[s++];
            if ((e & 1) == 0) r += d[e--];
            s >>= 1, e >>= 1;
        }
        return r;
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

int n, m, q;
ll d[606][606];
vi S, E, W;

vector<pi> v[606];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)d[i][j] = 1ll << 50;
    for (int i = 0; i < n; i++)d[i][i] = 0;

    S.resize(m);
    E.resize(m);
    W.resize(m);
    for (int i = 0, s, e, w; i < m; i++) {
        cin >> s >> e >> w;
        s--;
        e--;
        d[s][e] = d[e][s] = w;
        S[i] = s;
        E[i] = e;
        W[i] = w;
    }

    cin >> q;
    for (int i = 0, s, e, w; i < q; i++) {
        cin >> s >> e >> w;
        v[s].pb({w, e});
        v[e].pb({w, s});
    }
    for (int i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int r = 0;
    for (int i = 0; i < m; i++) {
        int s = S[i], e = E[i], w = W[i];

        for(int tt=0;tt<2;tt++){
            for (int x = 0; x < n; x++) {
                ll t = d[x][s] + w;

                // e -> ??

            }

            swap(s, e);
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
