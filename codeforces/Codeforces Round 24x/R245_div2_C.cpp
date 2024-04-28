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
vi v[100005];
int a[100005];
int b[100005];
vi r;

void dfs(int x, int y = -1, int c1 = -1, int c2 = -1) {
    if (c1 != -1) a[x] ^= c1;
    if (a[x] != b[x]) {
        r.pb(x);
        if (c1 == -1)c1 = 1;
        else c1 = c1 ^ 1;
    }
    c1 = c1 == -1 ? c1 : (c1 ^ 1);
    c2 = c2 == -1 ? c2 : (c2 ^ 1);
    for (int z: v[x]) {
        if (z == y)continue;
        dfs(z, x, c2, c1);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];
    dfs(1);
    cout << r.size() << '\n';
    for (int x: r)cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
