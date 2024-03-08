#include <cstring>
#include <cstdio>
#include <cmath>
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
vi v[105][105];
int vis[105];

int dfs(int x, int y, int c) {
    if (x == y)return 1;
    vis[x] = 1;
    int r = 0;
    for (int i = 0; i < v[c][x].size(); i++) {
        int nx = v[c][x][i];
        if(vis[nx])continue;
        r |= dfs(nx, y, c);
    }
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[c][a].pb(b);
        v[c][b].pb(a);
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int r = 0;
        for (int i = 1; i <= 100; i++) {
            memset(vis, 0, sizeof(vis));
            r += dfs(a, b, i);
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
