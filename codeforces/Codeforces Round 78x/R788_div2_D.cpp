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

ll calc(ll x) {
    ll v[3] = {x / 3, x / 3, x / 3};
    if (x % 3 >= 1)v[0]++;
    if (x % 3 >= 2)v[1]++;
    ll m3 = min(v[0], min(v[1], v[2]));
    ll m2 = v[0] * v[1] + v[1] * v[2] + v[0] * v[2] - m3 * 3;
    return m3 * 6 + m2 * 2;
}

void solve() {
    ll n;
    cin >> n;

    ll s = 2, e = 1000000, r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (calc(m) < n) s = m + 1;
        else r = m, e = m - 1;
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
