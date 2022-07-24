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


int n, m, t;
string a[1005];
int group_idx = 0;
pi group[1005][1005];
int color[1000005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int y, int x, int g = 0) {
    group[y][x] = {-1, 0};
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[y][x] != a[ny][nx] || group[ny][nx].F)continue;

        if (g == 0) {
            g = ++group_idx;
            color[g] = a[y][x] - '0';
        }
        dfs(ny, nx, g);
    }
    group[y][x] = {g, 0};
}


void calc() {
    queue<tuple<int, int, int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (group[i][j].F)
                q.push({i, j, group[i][j].F, group[i][j].S});
        }
    }
    while (!q.empty()) {
        auto [y, x, gid, dis] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || group[ny][nx].F)continue;

            group[ny][nx] = {gid, dis + 1};
            q.push({ny, nx, gid, dis + 1});
        }
    }
}

void solve() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)cin >> a[i];

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (group[i][j].F == 0)dfs(i, j);
    calc();

    while (t--) {
        ll y, x, cnt;
        cin >> y >> x >> cnt;
        y--, x--;

        auto [g, dis]= group[y][x];
        if (g == 0 || cnt <= dis) {
            cout << a[y][x] - '0' << '\n';
        }else {
            cout << (color[g] ^ (cnt % 2)) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
