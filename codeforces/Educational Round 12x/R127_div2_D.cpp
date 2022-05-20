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
int n, t;

ll check(ll s, ll e, ll a, ll b){
    ll c = min(a, b);
    b = max(a, b);
    a = c;
    return ab(s - a) + e - s + ab(e - b);
}

ll calc(vi &v, int s, int e, int m) {
    ll r = check(s, e, m, m);
    for (int i = 0; i <= n; i++) {
        ll tmp;
        if (i == 0) tmp = min(check(s, e, s, v[i]), check(s, e, e, v[i]));
        else if (i == n)tmp = min(check(s, e, s, v[i - 1]), check(s, e, e, v[i - 1]));
        else tmp = check(s, e, v[i-1], v[i]);
        r = min(tmp, r);
    }
    return r;
}

void solve() {
    cin >> n >> t;
    vi v(n);
    for (int &x: v)cin >> x;
    ll r = 0;
    for (int i = 1; i < n; i++)r += ab(v[i - 1] - v[i]);

    vi y = v;
    sort(y.begin(), y.end());
    int a = y[0], b = y.back();

    if (a != 1)r += calc(v, 1, a - 1, a);
    if (b < t) r += calc(v, b + 1, t, b);
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
