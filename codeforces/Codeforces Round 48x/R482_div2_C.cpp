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

vi v[300005];
int A, B, n;
int c[300005];
int d[300005];

int dfs(int x, int y = -1) {
    c[x] = 1;
    for (int z: v[x]) if (z != y) c[x] += dfs(z, x);
    return c[x];
}

int dfs2(int x, int y = -1) {
    if (x == B) d[x] = 1;
    for (int z: v[x]) if (z != y) d[x] += dfs2(z, x);
    return d[x];
}

void solve() {
    cin >> n >> A >> B;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll r = (ll) n * (n - 1);
    dfs(A);
    dfs2(A);

    ll a = c[A], b = c[B];
    for (int x: v[A]) if (d[x])a -= c[x];

    cout << r - a * b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
