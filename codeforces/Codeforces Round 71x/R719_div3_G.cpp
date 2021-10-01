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

int n, m, w;
int a[2005][2005];
ll d1[2005][2005];
ll d2[2005][2005];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

ll bfs(int sy, int sx, ll d[][2005]) {
    queue<pi> q;
    q.push({sy, sx});
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)d[i][j] = -1;
    d[sy][sx] = 0;

    ll r = 1ll << 60;
    while (!q.empty()) {
        auto[y, x] = q.front();
        q.pop();
        if (a[y][x] > 0) r= min(r, d[y][x] + a[y][x]);

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny == n || nx == m || a[ny][nx] == -1 || d[ny][nx] != -1)continue;
            q.push({ny, nx});
            d[ny][nx] = d[y][x] + w;
        }
    }
    return r;
}

void solve() {
    cin >> n >> m >> w;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) cin >> a[i][j];

    ll r1 = bfs(0, 0, d1);
    ll r2 = bfs(n - 1, m - 1, d2);

    ll r = r1 + r2;
    if (d1[n - 1][m - 1] != -1)r = min(r, d1[n - 1][m - 1]);

    if (r >= (1ll << 60)) r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    solve();
}
