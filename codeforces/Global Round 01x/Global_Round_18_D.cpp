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


vector<pi> v[200005], v2[200005];
int d[200005], vis[200005];
map<pi, int> ck;

void dfs(int x, int y, int val) {
    d[x] = val;
    for (auto[z, w]: v[x]) {
        if (z != y) {
            dfs(z, x, w == -1 || val == -1 ? -1 : val ^ (__builtin_popcount(w) % 2));
        }
    }
}


bool dfs2(int x, int k) {
    vis[x] = 1;
    if (d[x] == -1) d[x] = k;
    else if (d[x] != k) return false;

    for (auto[y, w]: v2[x]) {
        if (vis[y]) {
            if ((d[y] ^ w) != d[x]) return false;
        } else if (!dfs2(y, k ^ w))return false;
    }
    return true;
}

void print(int x, int y) {
    if (y != -1) {
        int r = ck.count({x, y}) ? ck[{x, y}] : d[x] ^ d[y];
        cout << x << " " << y << " " << r << '\n';
    }
    for (auto[z, w]: v[x])if (z != y)print(z, x);
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0, s, e, w; i < n - 1; i++) {
        cin >> s >> e >> w;
        v[s].pb({e, w});
        v[e].pb({s, w});
        if (w >= 0){
            ck[{s, e}] = ck[{e, s}] = w;
            v2[s].pb({e, __builtin_popcount(w) % 2});
            v2[e].pb({s, __builtin_popcount(w) % 2});
        }
    }
    for (int i = 0, s, e, w; i < m; i++) {
        cin >> s >> e >> w;
        v2[s].pb({e, w});
        v2[e].pb({s, w});
    }
    dfs(1, -1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && d[i] != -1) {
            if (!dfs2(i, d[i])) {
                cout << "NO\n";
                goto END;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !dfs2(i, 1)) {
            cout << "NO\n";
            goto END;
        }
    }

    cout << "YES\n";
    print(1, -1);

    END:;
    for (int i = 1; i <= n; i++) {
        v[i].clear(), v2[i].clear();
        d[i] = vis[i] = 0;
    }
    ck.clear();
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
