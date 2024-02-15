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
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0, mx = 0, mn = 1e9;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += a[j];
                mx = max(mx, a[j]);
                mn = min(mn, a[j]);
            }
        }
        if (sum >= l && sum <= r && mx - mn >= x) ans++;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
