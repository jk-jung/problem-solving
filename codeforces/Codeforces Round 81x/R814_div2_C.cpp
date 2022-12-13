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
    int n, q;
    cin >> n >> q;
    vi v(n), pos(n + 1);

    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)pos[i + 1] = v[i];

    vector<pi> r(n + 1, {1 << 30, -1});
    for (int i = 1, win; i < n; i++) {
        win = max(v[i - 1], v[i]);
        r[win].F = min(r[win].F, i);
        r[win].S = i;
        v[i] = win;
    }
    while (q--) {
        int x, y;
        cin >> x >> y;

        int k = pos[x];
        if(r[k].S == n - 1) {
            cout << max(0, y - r[k].F + 1) << endl;
        }else {
            cout << max(0, min(y, r[k].S) - r[k].F + 1) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
