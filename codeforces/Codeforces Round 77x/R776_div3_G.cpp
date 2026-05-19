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

const int MOD = 1000000007;
int n, m;

void bfs(int x, vector<vi> &v, vi &d, vi &vis) {
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    d[x] = 1;

    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (int y: v[x]) {
            if (!vis[y]) {
                vis[y] = vis[x] + 1;
                d[y] = d[x];
                q.push(y);
            } else if (vis[x] + 1 == vis[y]) {
                d[y] = (d[y] + d[x]) % MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) vis[i]--;
}

void solve() {
    cin >> n >> m;
    int s, t;
    cin >> s >> t;

    vector<vi> v(n + 1);
    vi d1(n + 1), vis1(n + 1);
    vi d2(n + 1), vis2(n + 1);

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    bfs(s, v, d1, vis1);
    bfs(t, v, d2, vis2);

    int r = d1[t];
    for (int x = 1; x <= n; x++) {
        for (int y: v[x]) {
            if(vis1[x] + vis2[y] == vis1[t] && vis1[x] == vis1[y]){
                r = (r + (ll) d1[x] * d2[y] % MOD) % MOD;
            }
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
