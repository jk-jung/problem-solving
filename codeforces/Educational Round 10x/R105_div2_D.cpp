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
int a[555][555];
vi r;
vector<pi> edges;

int go(vi &v) {
    if (v.size() == 1)return v[0];
    int m = v.size(), mm = 0;
    for (int i = 1; i < m; i++)mm = max(mm, a[v[0]][v[i]]);

    vector<vi> vv;
    for (int x: v) {
        int ok = -1;
        for (int i = 0; i < vv.size(); i++) {
            if (a[vv[i][0]][x] != mm)ok = i;
        }
        if (ok == -1) vv.pb({x});
        else vv[ok].pb(x);

    }

    int x = r.size();
    r.pb(mm);

    for (vi &nv: vv)
        edges.pb({go(nv), x});
    return x;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> a[i][j];

    vi v(n);
    r.resize(n);
    for (int i = 0; i < n; i++)v[i] = i;
    for (int i = 0; i < n; i++)r[i] = a[i][i];

    int hh = go(v);
    cout << r.size() << endl;
    for (int x: r)cout << x << " ";
    cout << endl;
    cout << hh + 1 << endl;
    for (auto[x, y]: edges) cout << x + 1 << " " << y + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
