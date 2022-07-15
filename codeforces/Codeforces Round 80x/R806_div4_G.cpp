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
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    vector<vector<ll>> d(n, vector<ll>(30));

    d[0][0] = v[0] - k;
    d[0][1] = v[0] / 2;

    ll r = max(d[0][0], d[0][1]);
    for (int i = 1; i < n; i++) {
        d[i][0] = d[i - 1][0] + v[i] - k;
        for (int j = 1; j < 30; j++) {
            ll cost = (v[i] >> j);
            ll x = d[i - 1][j] + cost - k;
            ll y = d[i - 1][j - 1] + cost;
            d[i][j] = max(x, y);
        }
        for (int j = 0; j < 30; j++)r = max(r, d[i][j]);
    }

    cout << r << endl;
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
