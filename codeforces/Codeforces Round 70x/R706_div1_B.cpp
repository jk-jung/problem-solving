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


void solve() {
    int n;
    cin >> n;
    vi v(n), a(n), b(n);
    for (int &x: v)cin >> x;

    int c = 1;
    a[0] = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] < v[i]) c++;
        else c = 1;
        a[i] = c;
    }
    c = 1;
    b[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i + 1] < v[i]) c++;
        else c = 1;
        b[i] = c;
    }

    vector<pi> vv;
    vi tot;
    for (int i = 0; i < n; i++) {
        if (i == 0 && b[0] > 1)vv.pb({a[0], b[0]});
        else if (i == n - 1 && a[n - 1] > 1)vv.pb({a[n - 1], b[n - 1]});
        else if (a[i] > 1 && b[i] > 1)vv.pb({a[i], b[i]});
    }
    for (auto[u, d]: vv) {
        tot.pb(u);
        tot.pb(d);
    }
    sort(tot.begin(), tot.end());
    int m = tot.size();
    int r = 0;
    for (int i = 0; i < vv.size(); i++) {
        auto[u, d] = vv[i];
        if (u > d) swap(u, d);
        if (d < 3) continue;

        int idx = m - 1;
        if (tot[idx] == d) idx--;
        if (tot[idx] == u) idx--;

        int ll = -1;
        if (idx >= 0)ll = tot[idx];
        if (ll >= d) continue;

        if (u == d) {
            if (d % 2 == 1) {
                r++;
            }
        }
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
