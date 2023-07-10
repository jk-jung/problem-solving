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

string s, a, b;
int n, m;

int go(int x, int y, vector<vi> &d, vector<vi> &pos) {
    if (x == m) return 0;
    if (y == n) return 1;
    int &r = d[x][y];
    if (r != -1) return r;
    r = 0;

    for (char z = a[x]; z <= b[x]; z++) {
        vi &v = pos[z - '0'];
        auto it = std::lower_bound(v.begin(), v.end(), y);

        if (it != v.end()) {
            r |= go(x + 1, *it + 1, d, pos);
        } else {
            r = 1;
        }
    }
    return r;
}

void solve() {
    cin >> s >> m >> a >> b;
    n = (int) s.size();
    vector<vi> v(m, vi(n, -1));
    vector<vi> pos(10);
    for (int i = 0; i < n; i++) {
        pos[s[i] - '0'].pb(i);
    }
    cout << (go(0, 0, v, pos) == 1 ? "YES" : "NO") << endl;
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
