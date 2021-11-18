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

ll calc(vi &v) {
    ll r = 0, L = 0;
    map<int, int> ck;
    for (int x: v)ck[x]++;
    for (auto[x, y]: ck) {
        r += L * y * (v.size() - L - y);
        L += y;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    vector<pi> v(n);
    ll L_tot = 0, R_tot = 0, tot = 0, r = 0;
    map<int, int> L, R;
    for (int i = 0; i < n; i++) {
        cin >> v[i].F >> v[i].S;
        a[i] = v[i].F;
        b[i] = v[i].S;
        R[v[i].S]++;
        R_tot++;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n;) {
        int k = v[i].F;
        vi cur;
        while (i < n && v[i].F == k) cur.pb(v[i++].S);

        for (int x: cur) {
            tot -= L_tot - L[x];
            R[x]--, R_tot--;

        }

        for (int x: cur) {
            ll t1 = R[x] * (L_tot - L[x]);
            ll t2 = L[x] * (R_tot - R[x]);

            r += tot - t1 - t2;
        }

        for (int x:cur) {
            L[x]++, L_tot++;
            tot += R_tot - R[x];
        }
    }

    cout << calc(a) + calc(b) - r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
