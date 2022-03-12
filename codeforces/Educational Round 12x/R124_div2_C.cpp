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

ll f(ll x, vector<ll> &v) {
    ll r = ab(x - v[0]);
    for (ll y: v)r = min(r, ab(x - y));
    return r;
}

void solve() {
    int n;
    cin >> n;
    int m = n - 1;
    vector<ll> a(n), b(n);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;

    ll r = min(ab(a[0] - b[0]) + ab(a[m] - b[m]), ab(a[0] - b[m]) + ab(a[m] - b[0]));
    r = min(r , f(a[0], b) + f(a[m], b) + f(b[0], a) + f(b[m], a));

    r = min(r, ab(a[0] - b[0]) + f(a[m], b) + f(b[m], a));
    r = min(r, ab(a[m] - b[m]) + f(a[0], b) + f(b[0], a));
    r = min(r, ab(a[0] - b[m]) + f(a[m], b) + f(b[0], a));
    r = min(r, ab(a[m] - b[0]) + f(a[0], b) + f(b[m], a));

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
