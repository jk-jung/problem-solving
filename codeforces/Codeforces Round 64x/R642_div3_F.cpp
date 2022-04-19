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
ll a[105][105];
bool vis[105][105];
ll d[105][105];

ll calc(ll v, int y = 0, int x = 0) {
    if (y == n)return -1;
    if (x == m)return -1;
    if (a[y][x] < v) return -1;
    if (y == n - 1 && x == m - 1) return a[y][x] - v;

    ll &r = d[y][x];
    if (vis[y][x])return r;
    vis[y][x] = true;

    r = 1ll << 60;
    ll v1 = calc(v, y + 1, x);
    ll v2 = calc(v, y, x + 1);
    if (v1 != -1) r = min(r, v1);
    if (v2 != -1) r = min(r, v2);

    if (r == (1ll << 60))r = -1;
    else r += a[y][x] - v;
    return r;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)cin >> a[i][j], a[i][j] -= (i + j);

    ll r = 1ll << 60;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            memset(vis, 0, sizeof(vis));
            ll t = calc(a[i][j]);
            if (t != -1)r = min(r, t);
        }
    cout << r << endl;
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
