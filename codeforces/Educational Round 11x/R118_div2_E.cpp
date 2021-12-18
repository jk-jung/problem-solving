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

int n, m;
vector<string> v;
vector<vi> r, ck;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_ok(int y, int x) {
    int ok = 0, no = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny == n || nx == m || ny < 0 || nx < 0 || v[ny][nx] == '#')continue;
        if (r[ny][nx]) ok++;
        else no++;
    }
    return ok > 0 && no <= 1;
}

void dfs(int y, int x) {
    r[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny == n || nx == m || ny < 0 || nx < 0 || v[ny][nx] == '#')continue;
        if (!is_ok(ny, nx) || r[ny][nx]) continue;
        dfs(ny, nx);
    }
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    r.resize(n, vi(m));

    for (auto &s: v)cin >> s;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 'L') dfs(i, j);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (r[i][j] && v[i][j] == '.')v[i][j] = '+';

    for (auto &s: v)cout << s << '\n';

    v.clear();
    r.clear();
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
