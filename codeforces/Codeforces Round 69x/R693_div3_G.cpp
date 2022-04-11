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

vi v[200005];
vi vv[200005];
int r[200005];
int d[200005];
int up[200005];
int vis[200005];
int n, m;

void bfs() {
    queue<int> q;
    q.push(1);

    vis[1] = 1;
    d[1] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        up[x] = max(0, d[x] - 1);
        for (int y: v[x]) {
            if (!vis[y]) {
                vv[x].pb(y);
                q.push(y);
                vis[y] = 1;
                d[y] = d[x] + 1;
            } else {
                up[x] = min(up[x], d[y]);
            }
        }
    }
}

int dfs(int x) {
    vis[x] = 1;
    r[x] = d[x];
    for (int y: v[x]){
        if(d[x] + 1 == d[y]) {
            if(!vis[y]) dfs(y);
            r[x] = min(r[x], r[y]);
        }else {
            r[x] = min(r[x], d[y]);
        }
    }
    return r[x];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)up[i] = 1 << 30;

    while (m--) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
    }

    for (int i = 1; i <= n; i++)vis[i] = 0;
    bfs();
    for (int i = 1; i <= n; i++)vis[i] = 0;
    dfs(1);

    for (int i = 1; i <= n; i++)cout << r[i] << " ";
    cout << endl;

    for (int i = 1; i <= n; i++)v[i].clear();
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
