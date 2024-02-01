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
int a[100005];
vi v[100005];

int dfs(int x, int y = -1, int c = 0) {
    if (c > m)return 0;
    int r = 0, ck = 1;
    for (int z: v[x]) {
        if (z == y)continue;
        r += dfs(z, x, a[z] ? c + 1 : 0);
        ck = 0;
    }
    return r + ck;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        x--, y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    cout << dfs(0, -1, a[0]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
