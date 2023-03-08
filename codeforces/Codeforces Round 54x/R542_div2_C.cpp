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
int a, b, c, d;
int idx = 0;
string v[55];
int t[55][55];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    t[y][x] = idx;
    v[y][x] = '1';
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || v[ny][nx] != '0')continue;
        dfs(ny, nx);
    }
}

void solve() {
    cin >> n >> a >> b >> c >> d;
    m = n;
    a--, b--, c--, d--;
    for (int i = 0; i < n; i++)cin >> v[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '0') {
                idx++;
                dfs(i, j);
            }
        }
    int r = 1 << 30;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    int cost = (i - y) * (i - y) + (j - x) * (j - x);
                    if (t[i][j] == t[a][b] && t[y][x] == t[c][d]) r = min(r, cost);
                }
            }
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

        solve();
}
