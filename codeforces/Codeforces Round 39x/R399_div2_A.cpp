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

map<ll, ll> cnt, c2;

ll f(ll x) {
    if (x < 2) return 1;
    if (cnt.count(x)) return cnt[x];
    return cnt[x] = f(x / 2) * 2 + 1;
}

ll o(ll x) {
    if (x < 2) return x == 1;
    if (c2.count(x)) return c2[x];
    return c2[x] = o(x / 2) * 2 + (x % 2 == 1);
}

ll go(ll n, ll i, ll j, ll s, ll e) {
    if (i > e || j < s) return 0;
    if (s <= i && j <= e) return o(n);
    if (n < 2)return 0;
    ll m = n / 2;
    ll c = f(m);

    ll r = 0;
    r += go(m, i, i + c - 1, s, e);
    r += go(n % 2, i + c, i + c, s, e);
    r += go(m, i + c + 1, j, s, e);
    return r;
}

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    cout << go(n, 1, f(n), l, r) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
