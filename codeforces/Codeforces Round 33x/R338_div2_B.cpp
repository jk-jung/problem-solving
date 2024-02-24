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

int n, m;
ll r = 0;
ll d[100005];
vi v[100005];

ll dfs(int x) {
    ll &t = d[x];
    if (t != -1)return t;
    t = 1;

    for (int y: v[x]) {
        if (y < x) {
            t = max(t, dfs(y) + 1);
        }
    }
    r = max(r, t * (ll)v[x].size());
    return t;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++)sort(v[i].begin(), v[i].end());

    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++)dfs(i);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
