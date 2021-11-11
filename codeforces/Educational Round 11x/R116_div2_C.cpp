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

ll n, k;
vi v;

ll get_cnt(ll m) {
    ll r = 0;
    for (int x: v) {
        r += m / x;
        m %= x;
    }
    return r;
}

int pw(int x) {
    int r = 1;
    while (x--)r *= 10;
    return r;
}

void solve() {
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++)cin >> v[i], v[i] = pw(v[i]);
    reverse(v.begin(), v.end());

    for (ll m = 9;; m = m * 10ll + 9) {
        ll t = get_cnt(m);
        if (t > k) {
            ll r = 0, mm = 1, need = t - k - 1;
            for (int x: v) {
                ll can = m / x;
                ll minus = max(0ll, min(can - mm, need));
                r += x * (can - minus);
                need -= minus;
                m %= x;
                mm = 0;
            }
            cout << r << endl;
            break;
        }
    }
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
