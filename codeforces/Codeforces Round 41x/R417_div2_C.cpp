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


ll m;


bool sf(pair<ll, ll> &x, pair<ll, ll> &y) {
    return x.F + x.S * m < y.F + y.S * m;
}

void solve() {
    ll n, S;
    cin >> n >> S;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)cin >> v[i].F, v[i].S = i + 1;
    ll s = 1, e = n, r = 0, rv = 0;
    while (s <= e) {
        m = (s + e) / 2;
        sort(v.begin(), v.end(), sf);

        ll tot = 0, val = 0;
        for (auto [x, y]: v) {
            ll k = x + y * m;
            if (val + k > S)break;
            val += k;
            tot++;
            if (tot == m)break;
        }
        if (tot == m)s = m + 1, r = m, rv = val;
        else e = m - 1;
    }
    cout << r << " " << rv << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
