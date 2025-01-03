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
    ll n, s, e;
    cin >> n >> s >> e;
    vector<ll> v(n);
    ll tot = 0;
    for (ll &x: v)cin >> x, tot += x;
    sort(v.begin(), v.end());
    ll r = 0;
    for (ll i = 0; i < n; i++) {
        ll cur = tot - v[i];
        if (cur < s)break;
        ll x = cur - e;
        ll y = cur - s;
        ll idx1 = max(i + 1, (ll) (lower_bound(v.begin(), v.end(), x) - v.begin()));
        ll idx2 = upper_bound(v.begin(), v.end(), y) - v.begin();
        r += max(0ll, idx2 - idx1);
    }

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
