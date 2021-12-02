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

int n, k;
vi v[200005];
int ck[200005];
int d[200005], r = 0;

int dfs(int x, int y = 0) {
    if (ck[x]) d[x] = 0;
    for (int z: v[x]) {
        if (z != y) d[x] = min(d[x], dfs(z, x) + 1);
    }
    return d[x];
}

void go(int x, int y = 0, int dep = 0) {
    if (dep >= d[x]) {
        r++;
        return;
    }

    for (int z: v[x]) {
        if (z != y) go(z, x, dep + 1);
    }
    if (x != 1 && v[x].size() == 1) r = 1 << 30;
}


void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        v[i].clear();
        ck[i] = 0;
        d[i] = 1 << 30;
    }

    for (int i = 0, x; i < k; i++) cin >> x, ck[x] = 1;

    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb(e), v[e].pb(s);
    }

    dfs(1);
    r = 0;
    go(1);
    cout << (r < (1<<30) ? r : -1) << endl;

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
