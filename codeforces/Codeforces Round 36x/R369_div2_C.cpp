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

int n, m, k;
int a[105][105];
ll d[105][105][105];
int c[105];


ll go(int idx, int group, int last) {
    if (idx == n + 1) return group == k ? 0 : 1ll << 60;

    ll &r = d[idx][group][last];
    if (r != -1)return r;

    r = 1ll << 60;
    if (c[idx] == 0) {
        for (int i = 1; i <= m; i++) {
            r = min(r, go(idx + 1, group + (i != last), i) + a[idx][i]);
        }
    } else {
        r = min(r, go(idx + 1, group + (c[idx] != last), c[idx]));
    }

    return r;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)cin >> c[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    ll r = go(1, 0, 101);
    cout << (r >= (1ll << 60) ? -1 : r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
