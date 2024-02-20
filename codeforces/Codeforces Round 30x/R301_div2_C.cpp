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
vector<string> a(505);
int c[505][505];
bool ok = false;
int x, y, x2, y2;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x) {
    c[y][x] = 1;
    if (y == y2 && x == x2) {
        ok = true;
        return;
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (ny == y2 && nx == x2) {
            ok = true;
            return;
        }
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || a[ny][nx] == 'X' || c[ny][nx])continue;

        dfs(ny, nx);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];

    cin >> y >> x >> y2 >> x2;
    x--, y--, x2--, y2--;
    dfs(y, x);

    if (!ok) {
        cout << "NO\n";
        return;
    }

    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int nx = x2 + dx[k];
        int ny = y2 + dy[k];
        if(nx == x && ny == y)cnt++;
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || a[ny][nx] == 'X')continue;
        cnt++;
    }

    if(x == x2 && y == y2) {
        cout << (cnt >= 1 ? "YES" : "NO");
    }
    else if (a[y2][x2] == '.') {
        cout << (cnt >= 2 ? "YES" : "NO");
    } else cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
