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
    ll n, s = 0;
    cin >> n;
    vector<ll> v(n), r(n);
    for (ll &x: v)cin >> x, s += x;
    ll m = (n + 1) * n / 2;

    if (s % m) {
        cout << "NO\n";
        return;
    }
    s /= m;

    for (int i = 0; i < n; i++) {
        int k = i == 0 ? n - 1 : i - 1;
        ll a = v[i] - 2 * s;
        ll b = v[k] - s;
        a = b - a;
        if(a % n || a <= 0) {
            cout << "NO\n";
            return;
        }
        r[i] = a / n;
    }

    cout << "YES\n";
    for (ll x: r)cout << x << " ";
    cout << '\n';
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
