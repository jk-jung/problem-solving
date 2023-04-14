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

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vi> v;
    vector<pi> r[5005];
    for (int i = 1; i <= n; i++)r[i].pb(mp(i, i));
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        r[x].pb(mp(n + i, x));
        r[y].pb(mp(n + i, y));
    }

    for (int i = 1; i <= n; i++) {
        cout << r[i].size() << endl;
        for (auto [x, y]: r[i])cout << x << " " << y << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
