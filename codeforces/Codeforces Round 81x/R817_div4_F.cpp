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
char v[55][55];
vector<pi> a;

void dfs(int y, int x) {
    v[y][x] = '.';
    a.pb({y, x});
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!i && !j)continue;
            int ny = y + i;
            int nx = x + j;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] == '.')continue;
            dfs(ny, nx);
        }
    }
}

bool check(int y, int x) {
    a.clear();
    dfs(y, x);

    if (a.size() != 3) return false;
    int sx = x, ex = x;
    int sy = y, ey = y;
    for (auto [y1, x1]: a) {
        sx = min(sx, x1), ex = max(ex, x1);
        sy = min(sy, y1), ey = max(ey, y1);
    }
    return ex - sx == 1 && ey - sy == 1;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> v[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '*' && !check(i, j)) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
