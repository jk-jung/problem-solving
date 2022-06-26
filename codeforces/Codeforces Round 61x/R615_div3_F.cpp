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
vi v[200005];
pi dis[200005];
int rst = -1;
vi abc(3);

pi dfs(int x, int y = -1) {
    pi r = {0, x};
    for (int z: v[x]) {
        if (z != y) {
            pi t = dfs(z, x);
            t.F++;
            r = max(r, t);
        }
    }
    return dis[x] = r;
}

void go(int x, int y = -1, pi up = {0, 0}) {
    pi a, b, c;
    if (up.F > 0)a = up, b = {0, x};
    else a = {0, x};
    for (int z: v[x]) {
        if (z == y)continue;
        auto t = dis[z];
        t.F++;

        if (t > a) {
            c = b;
            b = a;
            a = t;
        } else if (t > b) {
            c = b;
            b = t;
        } else if (t > c) {
            c = t;
        }
    }

    if (c.S > 0 && a.F + b.F + c.F > rst) {
        rst = a.F + b.F + c.F;
        abc[0] = a.S;
        abc[1] = b.S;
        abc[2] = c.S;
    }

    for (int z: v[x]) {
        if (z == y)continue;
        auto nxt = a;
        if (nxt.S == dis[z].S)nxt = b;
        nxt.F++;
        go(z, x, nxt);
    }
}

void solve() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);
    go(1);

    cout << rst << endl;
    for (int x: abc)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
