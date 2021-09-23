#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    int n, m;
    ll s = 0;

    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)cin >> a[i], s += a[i];

    cin >> m;
    vector<pi> v(m);
    for (int i = 0; i < m; i++)cin >> v[i].F >> v[i].S;

    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int k = lower_bound(a.begin(), a.end(), v[i].F) - a.begin();
        ll r = v[i].F + v[i].S;

        for (int j = k - 1; j < min(k + 1, (int) a.size()); j++) {
            if (j < 0) continue;
            ll c1 = max(0ll, v[i].F - a[j]);
            ll c2 = max(0ll, v[i].S - s + a[j]);
            r = min(r, c1 + c2);
        }
        cout << r << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
