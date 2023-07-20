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


int f(int x, int y, int k, vi &v) {
    if (k < 0 || k >= v.size())return 1 << 30;
    return ab(x - v[k]) + ab(y - v[k]);
}

void solve() {
    int n, m, c, e, v;
    cin >> n >> m >> c >> e >> v;
    vi a(c), b(e);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    int q;
    cin >> q;
    while (q--) {
        int x, y, x1, y1;
        cin >> y >> x >> y1 >> x1;
        if (y == y1) {
            cout << ab(x - x1) << endl;
        } else {
            int z0 = upper_bound(a.begin(), a.end(), x) - a.begin();
            int z1 = upper_bound(b.begin(), b.end(), x) - b.begin();
            int z2 = upper_bound(a.begin(), a.end(), x1) - a.begin();
            int z3 = upper_bound(b.begin(), b.end(), x1) - b.begin();

            int h = ab(y - y1);
            int r = 1 << 30;
            for (int i = -1; i <= 0; i++) {
                r = min(r, f(x, x1, z0 + i, a) + h);
                r = min(r, f(x, x1, z1 + i, b) + (h + v - 1) / v);
                r = min(r, f(x, x1, z2 + i, a) + h);
                r = min(r, f(x, x1, z3 + i, b) + (h + v - 1) / v);
            }
            cout << r << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
