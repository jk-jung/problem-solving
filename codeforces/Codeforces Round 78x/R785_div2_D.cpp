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

ll a, b, c;
ll d, e, f;

ll in(ll x) {
    ll y = x - a;
    if (y < 0 || y % b || y / b >= c) return -1;
    return y / b;
}


ll calc(ll x) {
    ll lcm = x * b / gcd(x, b);
    if (lcm != e)return 0;
    ll t = e / x;
    return t * t;
}

void solve() {
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    ll dd = d + e * f - e;

    if (e < b || e % b || in(d) == -1 || in(dd) == -1) {
        cout << 0 << endl;
        return;
    }
    if (in(d - e) == -1 || in(dd + e) == -1) {
        cout << -1 << endl;
        return;
    }

    ll r = 0;
    for (int x = 1; x * x <= e; x++) {
        ll y = e / x;

        r = (r + calc(x)) % 1000000007;
        if (x != y)r = (r + calc(y)) % 1000000007;
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