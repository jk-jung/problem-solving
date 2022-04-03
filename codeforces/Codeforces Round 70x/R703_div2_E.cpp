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

int n, m;
vector<pi> v[200005];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v[s].pb({e, w});
        v[e].pb({s, w});
    }

    vector<vi> d(n + 1, vi(51, 1 << 30));
    vector<vi> vis(n + 1, vi(51));
    d[1][0] = 0;

    priority_queue<tuple<int, int, int>> q;
    q.push({0, 1, 0});
    while (!q.empty()) {
        auto[dis, x, st] = q.top();
        q.pop();
        if (vis[x][st])continue;
        vis[x][st] = 1;

        for (auto[y, w]: v[x]) {
            int cost = (st == 0 ? 0 : (st + w) * (st + w));
            int nt = (st == 0 ? w : 0);
            if (d[x][st] + cost < d[y][nt]) {
                d[y][nt] = d[x][st] + cost;
                q.push({-d[y][nt], y, nt});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int x = d[i][0];
        if (x == (1 << 30))cout << -1 << " ";
        else cout << x << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
