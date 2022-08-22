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

vi v[200005];
vi r;
int n, m;

int dfs(int x, int y, int dep) {
    int cnt = 0;
    for (int z: v[x]) {
        if (z != y)cnt += dfs(z, x, dep + 1);
    }
    r.pb(dep -cnt);
    return cnt + 1;
}

void solve() {
    cin >> n >> m;

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1, -1, 0);
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());

    ll s = 0;
    for (int i = 0; i < m; i++)s += r[i];
    cout << s << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
