#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


int vis[100];
vi v[100];
vector<vi> g[4];

void dfs(int x, vi &t) {
    t.pb(x);
    vis[x] = 1;
    for (int y: v[x]) {
        if (!vis[y])dfs(y, t);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vi t;
            dfs(i, t);
            if (t.size() > 3) {
                cout << -1;
                return;
            }
            g[t.size()].pb(t);
        }
    }
    for (vi &t: g[2]) {
        if (g[1].empty()) {
            cout << -1;
            return;
        }
        vi &t1 = g[1].back();
        t.pb(t1[0]);
        g[1].pop_back();
    }
    for (vi &t: g[2])cout << t[0] << " " << t[1] << " " << t[2] << endl;
    for (vi &t: g[3])cout << t[0] << " " << t[1] << " " << t[2] << endl;
    for (int i = 0; i < g[1].size(); i += 3) {
        cout << g[1][i][0] << " " << g[1][i + 1][0] << " " << g[1][i + 2][0] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
