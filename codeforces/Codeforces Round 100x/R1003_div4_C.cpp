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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;
    sort(b.begin(), b.end());
    a[0] = min(a[0], b[0] - a[0]);
    for (int i = 1; i < n; i++) {
        ll dif = a[i] + a[i - 1];

        // a[i - 1] <= b[idx] - a[i]
        // a[i - 1] <= a[i]

        int idx = lower_bound(b.begin(), b.end(), dif) - b.begin();
        ll v1 = a[i-1] <= a[i] ? a[i] : 1ll << 60;
        ll v2 = idx == m ? 1ll << 60 : b[idx] - a[i];
        a[i] = min(v1, v2);
        if (a[i] == (1ll << 60)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
