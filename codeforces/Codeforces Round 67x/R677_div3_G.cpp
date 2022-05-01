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
#define eb    emplace_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))


int n, m, k;
int d[1005][1005];
vector<pi> v[1005];


void dij(int x) {
    int *dis = d[x];
    priority_queue<pi> q;
    dis[x] = 0;
    q.push({0, x});

    while (!q.empty()) {
        auto [dd, s] = q.top();
        dd = -dd;
        q.pop();
        if (dis[s] < dd)continue;

        for (auto [e, w]: v[s]) {
            if(dis[s] + w < dis[e]) {
                dis[e] = dis[s] + w;
                q.push({-dis[e], e});
            }
        }
    }
}

void solve() {
    memset(d, 63, sizeof(d));

    cin >> n >> m >> k;
    for (int i = 0, s, e, w; i < m; i++) {
        cin >> s >> e >> w;
        v[s].eb(e, w);
        v[e].eb(s, w);
    }

    for (int i = 1; i <= n; i++)dij(i);
    vector<pi> t(k);
    for (auto &[a, b]: t)cin >> a >> b;

    int r = 1 << 30;
    for (int s = 1; s <= n; s++) {
        for (auto [e, w]: v[s]) {
            int tmp = 0;
            for (auto [a, b]: t) {
                // a -> b
                // a -> s  e <- b
                // a -> e  s <- b
                tmp += min(d[a][b], min(
                        d[a][s] + d[b][e],
                        d[a][e] + d[s][b]
                ));
            }
            r = min(r, tmp);
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
