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

vi v[200005];
set<int> vis;
int n, k, s, e;
int dep[200005];
bool ck[200005];


bool dfs1(int x, int y = -1) {
    ck[x] = vis.count(x);
    dep[x] = y == -1 ? 0 : dep[y] + 1;

    for (int z: v[x]) if (z != y) ck[x] |= dfs1(z, x);
    return ck[x];
}

int dfs2(int x, int y = -1) {
    int r = 0;
    for (int z: v[x])if (z != y && ck[z])r += dfs2(z, x) + 2;
    return r;
}

void solve() {
    cin >> n >> k >> s >> e;
    for (int i = 0, x; i < k; i++)cin >> x, vis.insert(x);
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    vis.insert(e);

    dfs1(s);
    int r = dfs2(s) - dep[e];
    cout << r << endl;

    for (int i = 1; i <= n; i++)v[i].clear();
    vis.clear();
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
