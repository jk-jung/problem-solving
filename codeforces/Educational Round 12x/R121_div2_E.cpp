#include <string.h>
#include <stdio.h>
#include <math.h>
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
int c[300005];
int r[300005];
int up[300005];
int down[300005];
int cnt[300005];
vi v[300005];


int dfs(int x, int y = 0) {
    cnt[x] = c[x];
    for (int z: v[x])
        if (z != y) cnt[x] += dfs(z, x);
    return cnt[x];
}

int go(int x, int y = 0, int b_cnt = 0) {
    for (int z: v[x]) {
        if (z == y)continue;

        if (c[x] && cnt[z]) up[x] = 1;
        if (c[z] && cnt[x] - cnt[z] > 0) up[x] = 1;

        int nt = b_cnt + cnt[x] - cnt[z];
        up[x] |= go(z, x, nt);
    }
    return up[x];
}

void go2(int x, int y = 0, int b_cnt = 0) {
    int bs = 0, u = 0;
    for (int z: v[x]) if (z != y) u += up[z];
    for (int z: v[x]) bs += c[z];

    for (int z: v[x]) {
        if (z == y)continue;
        int nt = b_cnt + cnt[x] - cnt[z];

        if (down[x]) down[z] = 1;
        if (u - up[z] > 0)down[z] = 1;
        if (nt - 1 > 0 && c[x]) down[z] = 1;
        if (nt - 1 > 0 && bs - c[z] > 0) down[z] = 1;

        go2(z, x, nt);
    }
}

void check(int x, int y = 0) {
    r[x] |= c[x] | up[x] | down[x];

    for (int z: v[x]) {
        if (z == y)continue;

        r[z] |= c[x] | down[x];
        r[x] |= c[z];

        check(z, x);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> c[i];
    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    dfs(1);
    go(1);
    go2(1);
    check(1);

    for (int i = 1; i <= n; i++)cout << r[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
