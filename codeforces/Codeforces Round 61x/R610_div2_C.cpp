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
    ll n, T, a, b, ta = 0, tb = 0;
    cin >> n >> T >> a >> b;
    vector<pi> v(n);
    for (auto &[x, y]: v) {
        cin >> y;
        if (y == 0)ta++;
        else tb++;
    }
    for (auto &[x, y]: v)cin >> x;

    sort(v.begin(), v.end());

    ll aa = 0, bb = 0, r = 0, cur = 0;
    for (auto [x, y]: v) {
        if (cur <= x - 1) {
            ll rest = x - 1 - cur;
            ll ra = ta - aa;
            ll rb = tb - bb;

            ll k1 = min(rest, ra * a) / a;
            rest -= k1 * a;
            ll k2 = min(rest, rb * b) / b;
            r = max(r, aa + bb + k1 + k2);
        }

        if (y == 0) aa++;
        else bb++;
        cur = aa * a + bb * b;
    }
    if (cur <= T) r = n;

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
