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

int n, m;
vi v[100001];
int vis[100001];
set<pi> tt;
int cnt = 0;

void dfs(int x, int y = 0) {
    vis[x] = 1;
    cnt++;
    for (int z: v[x]) {
        pi k = mp(min(x, z), max(x, z));
        if (z == y)continue;
        if (!vis[z])dfs(z, x);
        else if (tt.empty() || tt.count(k)) {
            tt.insert(k);
        } else {
            cout << "NO" << endl;
            exit(0);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);

    cout << (!tt.empty() && cnt == n ? "FHTAGN!" : "NO") << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
