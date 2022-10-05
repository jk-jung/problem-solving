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

pair<ll, ll> to_gap(ll x, ll y) {
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    return mp(ab(x), ab(y));
}

bool sf(pair<pair<ll, ll>, int> &x, pair<pair<ll, ll>, int> &y) {
    ll a = x.F.F * y.F.S;
    ll b = x.F.S * y.F.F;
    if (a == b) return x.S < y.S;
    return a < b;
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    a *= 2;
    b *= 2;
    k *= 2;

    ll m = (a + b) / 2;
    if (k <= m) {
        cout << 2 << endl;
        return;
    } else {
        ll dif = k - m;
        ll gap = a - m;

        ll mid = gap / dif;
        if (mid % 2 == 0) mid++;
        vector<pair<pair<ll, ll>, int>> v;
        for (int i = -4; i <= 4; i += 2) {
            ll x = mid + i;
            if (x < 0)continue;
            auto t = to_gap(dif * x - gap, x);
            v.pb(mp(t, x));
        }
        sort(v.begin(), v.end(), sf);

        cout << v[0].S << endl;
    }
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
