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
ll a[100005];
vector<pi> v[100005];

ll dfs(int x, int y, ll dis) {
    if (dis > a[x] )return 0;
    ll cnt = 1;
    for (auto &[z, c]: v[x]) {
        if (z == y)continue;
        cnt += dfs(z, x, max((ll)c, dis + c));
    }
    return cnt;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 2, x, y; i <= n; i++) {
        cin >> x >> y;
        v[i].pb(pi(x, y));
        v[x].pb(pi(i, y));
    }

    cout << n - dfs(1, -1, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
