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
int a[405][405];
int da[405];
int db[405];

void bfs(int d[405], int s) {
    queue<pi> q;
    q.push({1, 0});
    memset(d, -1, sizeof(da));
    d[1] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (a[x][i] != s)continue;
            if (d[i] != -1)continue;
            d[i] = y + 1;
            q.push({i, y + 1});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    bfs(da, 1);
    bfs(db, 0);

    int r1 = da[n];
    int r2 = db[n];
    cout << ((r1 == -1 || r2 == -1) ? -1 : max(r1, r2)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
