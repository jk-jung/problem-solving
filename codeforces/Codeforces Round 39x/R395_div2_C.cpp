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


int n;
vi v[200005];
int c[100005];
int ok[100005];

void dfs(int x, int y = -1) {
    ok[x] = 1;
    for (int z: v[x]) {
        if (z == y)continue;
        dfs(z, x);
        if (c[x] != c[z] || !ok[z])ok[x] = 0;
    }
}

void dfs2(int x, int y = -1) {
    int o = 0;
    int idx = -1;
    set<int> cc;
    cc.insert(c[x]);
    for (int z: v[x]) {
        if (z == y)continue;
        if (!ok[z])o++, idx = z;
        else cc.insert(c[z]);
    }

    if (!o) {
        cout << "YES\n" << x << endl;
        exit(0);
    }
    if (y != -1)cc.insert(c[y]);
    if (o == 1 && cc.size() == 1) {
        dfs2(idx, x);
    }
}

void solve() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++)cin >> c[i];
    dfs(1);
    dfs2(1);
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
