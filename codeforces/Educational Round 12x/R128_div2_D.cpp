#include <string.h>
#include <stdio.h>
#include <math.h>
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

ll n, k;


ll length(ll x, ll y) {
    return max(x, y) - min(x, y) + 1;
}

ll check(ll x1, ll c1, ll x2, ll c2, ll x3, ll c3) {
    ll e = c1 * k;
    ll s = c2 * k;

    ll x = x3 + e - s;
    ll len = c3 * k;
    if (x - len <= 0 && 0 <= x + len)return length(x1 + e, x2 - s + e);
    if (x + len < 0) {
        ll need = -(x + len);
        if (need <= s)return length(x1 + e, x2 - (s - need) + e);
        return -1;
    }
    if (x - len > 0) {
        ll need = x - len;
        if (need <= e)return length(x1 + (e - need), x2 - s + (e - need));
        return -1;
    }
    return -1;
}

ll calc(vi v) {
    ll x1 = 0, c1 = 0;
    ll r = -1;
    for (int i = 0; i < n; i++) {
        ll xn = x1, cn = 0, x2 = x1, c2 = 0;
        for (int j = i; j < n; j++) {
            xn += v[j];
            if (!v[j])cn++;
        }

        for (int j = i; j < n; j++) {
            x2 += v[j];
            if (!v[j])c2++;

            ll x3 = xn;
            ll c3 = cn - c2;

            r = max(r, check(x1, c1, x2, c2, x3, c3));
        }

        x1 += v[i];
        if (!v[i]) c1++;
    }
    return r;
}

void solve() {
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    ll r = calc(v);
    for (int &x: v)x = -x;
    r = max(r, calc(v));

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
