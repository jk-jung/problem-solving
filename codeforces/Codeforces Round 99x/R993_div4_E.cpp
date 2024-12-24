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

ll k, l1, r1, l2, r2;

ll find_l(ll x) {
    return (l2 + x - 1) / x;
}

ll find_r(ll x) {
    return r2 / x;
}

void solve() {

    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll t = 1, rst = 0;
    while (t <= 1e9) {
        rst += max(0ll, min(r1, find_r(t)) + 1 - max(l1, find_l(t)));
        if (k == 1)break;
        t *= k;
    }
    cout << rst << endl;
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
