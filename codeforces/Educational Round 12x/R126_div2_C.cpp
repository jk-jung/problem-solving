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

int n;

bool ck(ll one, ll two, ll m) {
    ll n2 = m / 2;
    ll n1 = m - n2;

    if (n1 < one) return false;
    n2 += (n1 - one) / 2;
    return n2 >= two;
}

ll check(vi &v, int t) {
    ll one = 0, two = 0;
    for (int &x: v) {
        int dif = t - x;
        if (dif % 2)one++;
        two += dif / 2;
    }

    ll s = one, e = 1ll << 60, r = -1;
    while (s <= e) {
        ll m = (s + e) / 2;

        if (ck(one, two, m)) r = m, e = m - 1;
        else s = m + 1;
    }
    return r;
}

void solve() {

    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll r = min(check(v, v[0]), check(v, v[0] + 1));
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
