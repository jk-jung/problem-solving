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
    int n, m, idx = 0;
    cin >> n >> m;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x, y = idx++;
    sort(v.begin(), v.end());

    vi u(n);
    int t = 0, r = 1 << 30, tt = -1;
    for (int i = 0; i < v.size(); i++) {
        auto [x, y] = v[i];
        if (x <= m) m -= x, u[y] = 1, t++;
        else {
            int rank = n - t - 1;
            int target = t;
            if (target < n && !u[target]) r = rank + 1;
            else r = rank;
            if (r == rank)break;
            for (; tt < n; tt++)if (v[tt].S == target)break;
            for (int k = 0; k < i; k++) {
                u[v[k].S]--;
                for (int j = tt; j <= tt; j++) {
                    if (m + v[k].F - v[j].F >= 0) {
                        u[v[j].S]++;
                        if (target < n && !u[target]) r = min(r, rank + 1);
                        else r = min(r, rank);
                        u[v[j].S]--;
                    }
                }
                u[v[k].S]++;
            }
            break;
        }
    }
    if (r == (1 << 30))r = 0;
    cout << r + 1 << endl;
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
