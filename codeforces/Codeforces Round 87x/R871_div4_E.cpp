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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;

int go(int y, int x, vector<vi> &v, vector<vi> &ck) {
    ck[y][x] = 1;
    int r = v[y][x];
    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] == 0 || ck[ny][nx])continue;
        r += go(ny, nx, v, ck);
    }
    return r;
}

void solve() {
    cin >> n >> m;
    vector<vi> v(n, vi(m)), ck(n, vi(m));

    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> v[i][j];
    int r = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (!ck[i][j] && v[i][j])r = max(r, go(i, j, v, ck));
    cout << r << endl;
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
