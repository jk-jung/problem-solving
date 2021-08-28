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

#define mod 1000000007

int n, m;
vi v[105];
int c[105][105];
int p[105];
int d[105];
int r;

void dfs(int x, int y) {
    c[x][0] = 1;
    for (int z: v[x]) {
        if (z == y) continue;
        dfs(z, x);

        for (int i = 1; i < n; i++)
            c[x][i] += c[z][i - 1];
    }
}

void update(vi &cc) {
    if (cc.size() < m) return;
    for (int i = 0; i <= m; i++)d[i] = 0;
    d[0] = 1;
    for (int x: cc) {
        for (int k = m; k >= 1; k--)
            d[k] = (int) ((d[k] + x * (ll) d[k - 1]) % mod);
    }
    r = (r + d[m]) % mod;
}

void dfs2(int x, int y) {
    vi cc;
    for (int i = 0; i < n; i++) {
        for (int z: v[x]) {
            int *cnt = (z == y ? p : c[z]);
            if (cnt[i] > 0) cc.pb(cnt[i]);
        }
        update(cc);
        cc.clear();
    }

    for (int i = n; i >= 1; i--)p[i] = p[i - 1];
    p[0] = 0;
    for (int i = 0; i < n; i++)p[i] += c[x][i];

    for (int z: v[x]) {
        if (z == y) continue;

        for (int i = 1; i < n; i++)p[i] -= c[z][i - 1];
        dfs2(z, x);
        for (int i = 1; i < n; i++)p[i] += c[z][i - 1];
    }

    for (int i = 0; i < n; i++)p[i] -= c[x][i];
    for (int i = 0; i < n; i++)p[i] = p[i + 1];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    if (m == 2) {
        cout << n * (n - 1) / 2 << endl;
    } else {
        dfs(1, 0);
        dfs2(1, 0);

        cout << r << endl;
    }


    for (int i = 1; i <= n; i++)v[i].clear();
    memset(c, 0, sizeof(c));
    memset(p, 0, sizeof(p));
    r = 0;
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
