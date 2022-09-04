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
vi v[500005];
int d[500005];

void solve() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    vector<pi> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i].F;
        t[i].S = i + 1;
        d[i + 1] = 1;
    }
    sort(t.begin(), t.end());

    vi ord;
    for (auto [val, idx]: t) {
        if (d[idx] != val) {
            cout << -1 << endl;
            return;
        }
        for (int x: v[idx]) {
            if (d[x] == val) d[x]++;
        }
        ord.pb(idx);
    }
    for (int x: ord)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
