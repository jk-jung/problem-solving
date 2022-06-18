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

int n, m;
vector<vi> vis, root;
vector<vector<pi>> ck;
vi cy;
vector<string> v, c;


pi go(int y, int x, int dep = 1) {
    if (vis[y][x]) {
        if (vis[y][x] == 2) {
            cy.pb(dep - ck[y][x].F);
            ck[y][x] = {0, cy.size() - 1};
        }
    } else {
        vis[y][x] = 2;
        ck[y][x] = {dep, 0};

        if (v[y][x] == 'U') ck[y][x] = go(y - 1, x, dep + 1);
        if (v[y][x] == 'D') ck[y][x] = go(y + 1, x, dep + 1);
        if (v[y][x] == 'L') ck[y][x] = go(y, x - 1, dep + 1);
        if (v[y][x] == 'R') ck[y][x] = go(y, x + 1, dep + 1);

        vis[y][x] = 1;
    }

    return {ck[y][x].F + 1, ck[y][x].S};
}

void solve() {
    cin >> n >> m;
    v.resize(n), c.resize(n);
    ck.clear(), vis.clear(), root.clear();
    ck.resize(n, vector<pi>(m)), vis.resize(n, vi(m)), root.resize(n, vi(m));

    for (auto &x: c)cin >> x;
    for (auto &x: v)cin >> x;

    int r = 0, black = 0;

    cy.clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0) {
                go(i, j);
            }
        }

    set<pi> tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int len = cy[ck[i][j].S];
            pi key = {ck[i][j].S, ck[i][j].F % len};
            if (ck[i][j].F == 1) r += len;
            if (c[i][j] == '0' && !tmp.count(key)) {
                black ++;
                tmp.insert(key);
            }
        }
    }
    cout << r << " " << black << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
