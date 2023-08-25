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
int c[10005];
vi v[10005];

int dfs(int x, int p, int d) {
    int r = c[x] == d ? 0 : 1;
    for (int y: v[x]) {
        if (y == p) continue;
        r += dfs(y, x, c[x]);
    }
    return r;
}

void solve() {
    cin >> n;
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        v[x].pb(i);
        v[i].pb(x);
    }
    for (int i = 1; i <= n; i++)cin >> c[i];
    cout << dfs(1, -1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
