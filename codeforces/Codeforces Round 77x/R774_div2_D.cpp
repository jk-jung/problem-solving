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
pi d[200005][2];
int tr[200005][2];
int r[200005];


void add(pi &a, pi b) {
    a.F += b.F;
    a.S += b.S;
}

pi best(pi a, pi b) {
    if (a.F == b.F) return a.S < b.S ? a : b;
    return a.F > b.F ? a : b;
}


pi go(int x, int ok, int y = -1) {
    if (d[x][ok] != mp(0, 0)) return d[x][ok];

    pi r1 = {1, v[x].size()};
    pi r2 = {0, 1};
    for (int z: v[x]) {
        if (z == y)continue;

        add(r1, go(z, 0, x));
        add(r2, go(z, 1, x));
    }

    if (ok) {
        d[x][ok] = best(r1, r2);
        tr[x][ok] = d[x][ok] == r1 ? 1 : 0;
    } else {
        d[x][ok] = r2;
    }
    return d[x][ok];
}

void dfs(int x, int ok, int y = -1) {
    int nt = tr[x][ok];
    if(nt)r[x] = v[x].size();
    else r[x] = 1;

    for (int z: v[x]) {
        if (z == y)continue;

        dfs(z, nt ^ 1, x);
    }
}


void solve() {
    cin >> n;
    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    if (n == 2) {
        cout << "2 2\n1 1\n";
        return;
    }

    auto x = go(1, 0);
    auto y = go(1, 1);
    auto rr = best(x, y);
    int ok = rr == x ? 0 : 1;

    dfs(1, ok);
    cout << rr.F << " " << rr.S << endl;
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
