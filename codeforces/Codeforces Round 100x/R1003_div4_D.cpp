#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v;
    vector<vi> a(n);
    for (ll i = 0; i < n; i++) {
        ll s = 0;
        a[i].resize(m);
        for (ll j = 0, x; j < m; j++) {
            cin >> x;
            a[i][j] = x;
            s += m * x;
        }
        v.pb(mp(-s, i));
    }
    sort(v.begin(), v.end());
    vector<ll> f;
    for (auto &[x, y]: v) {
        for (int k: a[y])f.pb(k);
    }
    ll r = 0;
    for (ll i = 0; i < f.size(); i++)r += ((ll)f.size() - i) * f[i];
    cout << r << endl;
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
