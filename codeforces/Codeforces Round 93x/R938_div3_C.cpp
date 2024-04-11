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

    ll s = 0, e = n - 1;
    while (k) {
        if (s < n && v[s] == 0) {
            s++;
            continue;
        }
        if (e >= 0 && v[e] == 0) {
            e--;
            continue;
        }
        if (s > e)break;
        ll x = min(v[s], v[e]);
        x = min(x, k / 2);
        if (x == 0) {
            v[s] -= k;
            break;
        }
        v[s] -= x;
        k -= x;
        if (s != e) {
            v[e] -= x;
            k -= x;
        }
    }
    ll r = 0;
    for (ll x: v)if (x <= 0)r++;
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
