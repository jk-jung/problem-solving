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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;

    ll s = v[0], e = v[0] + (1ll << 50), r = v[0];
    while (s <= e) {
        ll m = (s + e) / 2;

        bool ok = true;
        ll t = m;
        for (int i = 1; i < n; i++) {
            if (v[i] * 100 > t * k) ok = false;
            t += v[i];
        }
        if (ok)e = m - 1, r = m;
        else s = m + 1;
    }
    cout << r - v[0] << endl;
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
