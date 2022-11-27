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
int d[300005];
int cnt[300005];
int n;

int go(int x, int y = -1) {
    int &r = d[x];
    if (r != -1)return r;

    r = 0;
    for (int a: v[x]) {
        if (a == y)continue;
        r = max(r, cnt[a] - 1);
        for (int b: v[x]) {
            if (b == y || a == b) continue;
            r = max(r, cnt[a] - 1 + go(b, x));
        }
    }
    return r;
}

int dfs(int x, int y = -1) {
    cnt[x] = 1;
    for (int &z: v[x])if (z != y)cnt[x] += dfs(z, x);
    return cnt[x];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)d[i] = -1, v[i].clear(), cnt[i] = 0;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1);
    cout << go(1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
