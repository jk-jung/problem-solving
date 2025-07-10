#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


int n;
vi v[1005];
vector<pi> redundant;
set<pi> used;

int root[1005];

void dfs(int x, int y, int r) {
    root[x] = r;
    for (int z: v[x]) {
        if (z == y)continue;
        if (root[z]) {
            if (!used.count(mp(z, x))) {
                redundant.pb(mp(x, z));
                used.insert(mp(x, z));
            }
        } else dfs(z, x, r);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    vi roots;
    for (int i = 1; i <= n; i++)if (!root[i])dfs(i, 0, i), roots.pb(i);

    cout << redundant.size() << endl;
    for (int i = 0; i < redundant.size(); i++) {
        auto [x, y] = redundant[i];
        cout << x << " " << y  << " 1 " << roots[i + 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
