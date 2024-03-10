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
    int n;
    cin >> n;
    vi deg(n), xr(n);
    vector<pi> r;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> deg[i] >> xr[i];
        if (deg[i] == 1)q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (deg[x] != 1)continue;
        int y = xr[x];
        r.pb(mp(x, y));
        deg[x] = xr[x] = 0;
        xr[y] ^= x;
        if (--deg[y] == 1)q.push(y);
    }
    cout << r.size() << endl;
    for (auto &p: r) {
        cout << p.F << " " << p.S << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
