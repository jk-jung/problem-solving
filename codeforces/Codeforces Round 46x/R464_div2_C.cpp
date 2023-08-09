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
    vi v(n);
    for (int &x: v)cin >> x;
    int s, e, r = 0;
    cin >> s >> e;
    int m = e - s, t = 0;
    vector<pi> tt;
    for (int i = 0; i < n * 2; i++) {
        t += v[i % n];
        if (i >= m - 1) {
            r = max(r, t);
            tt.pb(pi(i, t));
            t -= v[(i - m + 1) % n];
        }
    }
    int rr = 1 << 30;
    for (auto [x, y]: tt) {
        if (y != r)continue;
        int k = s - (x - m + 1);
        if (k <= 0)k += n;
        if (k <= 0)k += n;
        if (k <= 0)k += n;
        rr = min(rr, k);
    }
    cout << rr << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
