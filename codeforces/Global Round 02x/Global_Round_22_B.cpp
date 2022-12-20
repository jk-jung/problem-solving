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
    vector<ll> v(n), r(n + 1);
    for (ll i = n - k; i < n; i++)cin >> v[i];
    for (ll i = n - 1; i > n - k; i--) r[i] = v[i] - v[i - 1];
    ll t = v[n - k];
    r[n] = 1 << 30;
    for (ll i = n - k; i >= 1; i--) {
        ll x = min(r[i + 1], (t + i) / (i + 1));
        r[i] = x;
        t -= x;
    }
    r[0] = t;
    for (ll i = 0; i < n - 1; i++)
        if (r[i] > r[i + 1]) {
            cout << "NO\n";
            return;
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
