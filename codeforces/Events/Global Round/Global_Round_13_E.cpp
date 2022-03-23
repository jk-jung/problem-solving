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
int fib[200005];
vector<pi> v[200005];
int xx, yy;

int dfs(int x, int y = -1) {
    int r = 1;
    for (auto[z, t]: v[x])if (z != y && t)r += dfs(z, x);
    return r;
}

int cut(int x, int y, pi &edge, int tar, int tar2) {
    int r = 1;
    for (auto &t: v[x])if (t.F != y && t.S)r += cut(t.F, x, t, tar, tar2);

    if (r == tar || r == tar2) {
        if (xx == -1) {
            edge.S = 0;
            xx = x;
            yy = y;
        }
    }
    return r;
}

bool check(int x, int y = -1) {
    int c = dfs(x, y);
    if (!fib[c]) return false;
    if (c <= 2) return true;

    xx = yy = -1;
    pi dummy;
    cut(x, y, dummy, fib[c], c - fib[c]);

    if (xx == -1 && yy == -1)return false;

    return check(xx, yy) && check(x, y);
}

void solve() {
    cin >> n;
    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb({e, 1});
        v[e].pb({s, 1});
    }
    int a = 1;
    int b = 1;
    fib[1] = 1;
    for (;;) {
        int c = a + b;
        a = b;
        b = c;
        if (b > 200000)break;
        fib[b] = a;
    }
    cout << (check(1) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
