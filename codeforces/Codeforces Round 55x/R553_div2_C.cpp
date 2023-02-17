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

ll m = 1000000007;

ll f(ll e) {
    vector<ll> v(2);
    for (ll i = 0, y = 0, st = 0; i < 62; i++, st ^= 1) {
        ll x = y;
        y += (1ll << i);
        ll len = min(y - 1, e) - x + 1;
        if (len > 0) v[st] = (v[st] + len) % m;
    }
    return (v[0] * v[0] % m + v[1] * v[1] % m + v[1]) % m;
}

void solve() {
    ll s, e;
    cin >> s >> e;
    s--, e--;
    cout << (f(e) - f(s - 1) + m) % m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
