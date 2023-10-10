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

int n, k;
int r;
int c[200005];
int b[200005];
vi v[200005];

void dfs(int x, int y = -1) {
    c[x] = y == -1 ? 0 : c[y] + 1;
    for (int z: v[x])if (z != y)dfs(z, x);
}

int dfs2(int x, int y = -1, int d = 0) {
    b[x] = d;
    for (int z: v[x])
        if (z != y) {
            b[x] = max(b[x], dfs2(z, x, d + 1));
        }
    if (c[x] < d)r = max(r, b[x]);
    return b[x];
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(k);
    dfs2(1);
    cout << r * 2 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
