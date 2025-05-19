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
    ll n;
    cin >> n;
    vector<ll> v(n);
    vector<ll> cnt(50);
    for (ll &x: v) {
        cin >> x;
        for (int i = 0; i < 50; i++) {
            if (x >> i & 1)cnt[i]++;
        }
    }

    ll rr = 0;
    for (ll x: v) {
        ll r = 0;

        for (int i = 0; i < 50; i++) {
            if (x >> i & 1) {
                r += (1ll << i) * (n - cnt[i]);
            } else {
                r += (1ll << i) * cnt[i];
            }
        }
        rr = max(rr, r);
    }
    cout << rr << endl;

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
