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


int n, k;

ll calc(vi v) {
    ll ss = 0;
    map<ll, ll> ck;
    for (int x: v) {
        ss += x;
        if (++ck[x] == k)return 0;
    }

    ll last = ck.begin()->F, cnt = 0;
    ll r = 1ll << 60, t = 0;
    for (auto [x, y]: ck) {
        t += (x - last) * cnt;
        cnt += y;
        ss -= x * y;

        if (cnt >= k) {
            r = min(r, t - cnt + k);
            break;
        } else {
            ll n1 = k - cnt;
            ll n2 = n - k;
            ll tmp = n1 * x + n2 * (x + 1);
            r = min(r, t + ss - tmp);
        }
        last = x;
    }
    return r;
}

void solve() {
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    ll r = calc(v);
    for (int &x: v)x = 1000000000 - x;
    r = min(r, calc(v));

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
