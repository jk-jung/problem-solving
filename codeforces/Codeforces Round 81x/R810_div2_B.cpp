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
    vi v(n);
    vector<vi> vv(n);
    for (int &x: v)cin >> x;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        vv[x].pb(y);
        vv[y].pb(x);
    }
    if (m % 2 == 0) {
        cout << 0 << endl;
    } else {
        int r = 1 << 30;
        for (int i = 0; i < n; i++) {
            if (vv[i].size() % 2) {
                r = min(r, v[i]);
            } else {
                for (int y: vv[i]) {
                    r = min(r, v[i] + v[y]);
                }
            }
        }
        cout << r << endl;
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
