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
    int n, t;
    cin >> n >> t;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;
    sort(v.begin(), v.end());
    int r = 1 << 30;
    t -= v.back().F;
    if (t <= 0)r = 1;
    if (t > 0) {
        for (auto [x, y]: v) {
            int dif = x - y;
            if (dif <= 0) continue;
            r = min(r, 1 + (t + dif - 1) / dif);
        }
    }

    if (r == (1 << 30))r = -1;
    cout << r << endl;
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
