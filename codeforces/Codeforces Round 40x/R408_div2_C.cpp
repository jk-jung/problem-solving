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

int a[300005];
vi v[300005];
int n, m = -(1 << 30);
int d1 = 0;

int dfs(int x, int y = -1) {
    vi t;
    for (int z: v[x]) {
        if (z != y) {
            int k = dfs(z, x);
            if (k != -1) t.pb(k);
        }
    }
    sort(t.rbegin(), t.rend());
    if (t.size() >= 2)d1 = max(d1, t[0] + t[1] + 2);
    if (t.size() >= 1) {
        if (a[x] == m)d1 = max(d1, t[0] + 1);
        return t[0] + 1;
    }
    if (a[x] == m) {
        return 0;
    }
    return -1;
}

void dfs2(int x, int y = -1, int dep = 0) {
    if (dep >= 2 && a[x] == m - 1) {
        cout << m + 1 << endl;
        exit(0);
    }
    for (int z: v[x]) {
        if (z != y)dfs2(z, x, dep + 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i], m = max(m, a[i]);
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);

    if (d1 >= 3)cout << m + 2;
    else if (d1 >= 1)cout << m + 1;
    else {
        for (int i = 1; i <= n; i++)
            if (a[i] == m) {
                dfs2(i);
            }
        cout << m << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
