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
vi v[100005];
int w[100005];
int leaf[100005];
int parent[100005];
int r;
vi rr;

int dfs(int x, int y = -1) {
    parent[x] = y;
    int m = 0;
    w[x] = 1;
    for (int z: v[x]) {
        if (z != y) {
            int t = dfs(z, x);
            m = max(m, t);
            w[x] += t;
            leaf[x] = leaf[z];
        }
    }

    if (leaf[x] == 0)leaf[x] = x;
    m = max(m, n - w[x]);
    if (r == m) rr.pb(x);
    else if (r > m) {
        r = m;
        rr = {x};
    }
    return w[x];
}

void solve() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    r = 1 << 30;
    rr.clear();
    dfs(1);

    assert(rr.size() <= 2);
    if (rr.size() == 1) {
        cout << "1 " << v[1][0] << endl;
        cout << "1 " << v[1][0] << endl;
    } else {
        int x = rr[1];
        int y = leaf[rr[0]];

        cout << parent[y] << " " << y << endl;
        cout << x << " " << y << endl;
    }

    for (int i = 1; i <= n; i++)v[i].clear(), w[i] = 0, leaf[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
