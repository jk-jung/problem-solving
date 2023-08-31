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
int c[100005];
int t[100005];
vi v[100005];

ll dfs(int x) {
    t[x] = 1;
    ll r = c[x];
    for (int &y: v[x]) if (!t[y])r = min(r, dfs(y));
    return r;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> c[i];
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll r = 0;
    for (int i = 1; i <= n; i++) {
        if (!t[i])r += dfs(i);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
