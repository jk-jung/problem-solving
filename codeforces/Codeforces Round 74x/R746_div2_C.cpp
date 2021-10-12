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

vi v[100005];
int xo[100005];
int tot, idx;

int dfs(int x, int y) {
    for (int z: v[x]) if (z != y) xo[x] ^= dfs(z, x);
    if(idx == 0 && xo[x] == tot) idx = x;
    return xo[x];
}

int dfs2(int x, int y, int t) {
    int r = (x == t ? xo[x] : 0);
    if (t == -1 || x == t) xo[x] = -1;
    for (int z: v[x]) {
        if (z != y) r += dfs2(z, x, x == t ? -1 : t);
    }
    xo[x] ^= r;
    return r;
}

void solve() {
    int n, k;
    cin >> n >> k;

    tot = 0, idx = 0;
    for (int i = 1; i <= n; i++)cin >> xo[i], tot ^= xo[i];
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    bool ok = false;
    if (tot == 0) ok = true;
    else if (k - 1 >= 2) {
        dfs(1, 0);
        dfs2(1, -1, idx);
        for (int j = 1; j <= n; j++)
            if (xo[j] == tot) ok = true;

    }

    cout << (ok ? "YES\n" : "NO\n");

    for (int i = 1; i <= n; i++) v[i].clear();
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