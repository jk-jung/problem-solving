#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int sx, sy, ex, ey, n;
    cin >> sx >> sy >> ex >> ey >> n;
    if (sx > ex)swap(sx, ex);
    if (sy > ey)swap(sy, ey);

    set < pi > s;

    while (n--) {
        int x, y, r;
        cin >> x >> y >> r;

        for (ll i = max(sx, x - r); i <= min(ex, x + r); i++) {
            ll d1 = (x - i) * (x - i) + (sy - y) * (sy - y);
            ll d2 = (x - i) * (x - i) + (ey - y) * (ey - y);
            if (d1 <= r * r)s.insert(pi(sy, i));
            if (d2 <= r * r)s.insert(pi(ey, i));
        }
        for (ll i = max(sy, y - r); i <= min(ey, y + r); i++) {
            ll d1 = (y - i) * (y - i) + (sx - x) * (sx - x);
            ll d2 = (y - i) * (y - i) + (ex - x) * (ex - x);
            if (d1 <= r * r)s.insert(pi(i, sx));
            if (d2 <= r * r)s.insert(pi(i, ex));
        }
    }
    ll tot = (ex - sx + 1) * 2 + (ey - sy - 1) * 2;
    cout << tot - s.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
