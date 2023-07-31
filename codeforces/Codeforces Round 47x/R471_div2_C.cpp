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

vector<ll> d;

ll f(ll x) {
    ll l = 0, r = 1e9 + 1;
    while (l < r - 1) {
        ll m = (l + r) / 2;
        if (m * m > x)
            r = m;
        else
            l = m;
    }
    return l;
}

void solve() {
    ll L, R;
    cin >> L >> R;
    ll r = upper_bound(d.begin(), d.end(), R) - lower_bound(d.begin(), d.end(), L);
    r += f(R)  - f(L - 1);
    cout << r << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll L = 1000000000000000000ll;
    vector<ll> t = {1};
    for (ll i = 2; i <= 1000000; i++)
        for (ll c = i * i * i; c <= L; c *= i) {
            t.push_back(c);
            if (c > L / i) break;
        }
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    for (ll x: t) {
        ll y = f(x);
        if (y * y != x)d.pb(x);
    }


    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
