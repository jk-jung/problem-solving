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
    ll t;
    cin >> n >> t;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    vector<vector<ll>> d(n + 1, vector<ll>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        ll a = v[i - 1];
        for (int k = 0; k <= i; k++) {
            d[i][k] = max(0ll, max(a, d[i - 1][k] + a));
            if (k) {
                d[i][k] = max(d[i][k], max(a + t, d[i - 1][k - 1] + a + t));
            }
        }
    }
    ll r = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            r = max(r, d[j][i]);
        }
        cout << r << " ";
    }
    cout << endl;
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
