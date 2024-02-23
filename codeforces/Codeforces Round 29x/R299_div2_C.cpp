#include <cstring>
#include <cstdio>
#include <cmath>
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

ll A, B, n;
ll l, t, m;

bool ok(ll mid) {
    ll cnt = mid - l + 1;
    ll ss = cnt * (A + (l - 1) * B);
    ll ee = A + (mid - 1) * B;
    if (ee > t)return false;
    if (ss > t * m) return false;
    ll k = cnt * (cnt - 1) / 2 * B;
    return ss + k <= t * m;
}

void solve() {
    cin >> A >> B >> n;
    while (n--) {
        cin >> l >> t >> m;
        ll s = l, e = 1 << 30, r = -1;
        while (s <= e) {
            ll mid = (s + e) / 2;
            if (ok(mid)) s = mid + 1, r = mid;
            else e = mid - 1;
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
