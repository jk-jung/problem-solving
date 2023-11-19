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
int c[1005], ck;
int vis[1005];
vi v[1005];

int dfs(int x) {
    vis[x] = 1;
    int r = 1;
    if (c[x]) ck = 1;
    for (int y: v[x]) if (!vis[y])r += dfs(y);
    return r;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0, x; i < k; i++)cin >> x, c[x] = 1;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    ll cnt = 0;
    ll r = 0, a = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ck = 0;
            ll t = dfs(i);
            if (ck){
                a = max(a, t);
                r += t * (t - 1) / 2;
            }
            else cnt += t;
        }
    }
    r += (cnt) * (cnt - 1) / 2;
    cout << r + cnt * a - m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
