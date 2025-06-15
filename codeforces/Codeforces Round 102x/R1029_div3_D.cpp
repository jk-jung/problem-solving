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
    for (ll &x: v)cin >> x;
    ll p = n * n - 1;
    ll q = v[0] * n - v[n - 1];
    if (q % p) {
        cout << "NO\n";
        return;
    }
    ll y = q / p;
    ll x = v[0] - n * y;
    if (x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }
    for (ll i = 1; i <= n; i++) {
        if (x * i + (n - i + 1) * y != v[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
