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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;

    set<ll> ck;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1)ck.insert(a[i] + b[i]);
    }
    if (ck.empty()) {
        sort(a.begin(), a.end());
        ll s = a[n - 1];
        ll e = a[0] + k;
        cout << e - s + 1 << endl;
    } else if (ck.size() > 1) {
        cout << "0\n";
    } else {
        ll val = *ck.begin();
        vector<ll> r;
        for (int i = 0; i < n; i++) {
            if (b[i] == -1) {
                r.pb(val - a[i]);
            }
        }
        if (r.empty()) {
            cout << "1\n";
        } else {
            sort(r.begin(), r.end());
            if (0 <= r[0] && r.back() <= k) {
                cout << "1\n";
            } else cout << "0\n";
        }
    }
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
