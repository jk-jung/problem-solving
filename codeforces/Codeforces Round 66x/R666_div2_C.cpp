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

ll d[100005];
ll g, n;

ll go(ll x) {
    x %= n;
    if (x < 0)x += n;

    ll &r = d[x];
    if (r != -1) return r;
    return r = go(x + g) + g;
}

void solve() {
    memset(d, -1, sizeof(d));
    d[0] = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v) cin >> x;
    g = n;
    for (; gcd(g, n) != 1; g--);

    cout << 1 << " " << g << endl;
    for (int i = 0; i < g; i++) {
        ll t = go(v[i]);
        v[i] += t;
        cout << t << " ";
    }
    cout << endl;

    cout << n - g + 1 << " " << n << endl;
    for (int i = n - g; i < n; i++) {
        ll t = go(v[i]);
        v[i] += t;
        cout << t << " ";
    }
    cout << endl;

    cout << 1 << " " << n << endl;
    for (ll x: v)cout << -x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
