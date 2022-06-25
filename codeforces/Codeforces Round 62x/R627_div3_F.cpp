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

int n;
int c[200005];
vi v[200005];
int val[200005];
int r[200005];

int dfs(int x, int y = -1) {
    val[x] += c[x];
    for (int z: v[x]) {
        if (z == y)continue;
        int t = dfs(z, x);
        if (t > 0)val[x] += t;
    }
    return val[x];
}

void go(int x, int y = -1, int up = 0) {
    up = max(up, 0);
    int cnt = c[x] + up;
    for (int z: v[x]) {
        if (z != y && val[z] > 0) cnt += val[z];
    }

    r[x] = cnt;

    for (int z: v[x]) {
        if (z != y) {
            if (val[z] > 0) cnt -= val[z];
            go(z, x, cnt);
            if (val[z] > 0) cnt += val[z];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> c[i], c[i] = c[i] == 0 ? -1 : 1;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);
    go(1);

    for (int i = 1; i <= n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
