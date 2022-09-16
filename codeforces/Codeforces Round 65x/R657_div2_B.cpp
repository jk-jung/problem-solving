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

void solve() {
    ll l, r, m;
    cin >> l >> r >> m;
    ll dif = r - l;

    for (ll a = l; a <= r; a++) {
        ll x = m % a;
        ll t = (a - m % a) % a;
        if (0 <= t && t <= r - l) {
            cout << a << " " << l << " " << l + t << endl;
            return;
        }
        if (0 <= x && x <= r - l) {
            cout << a << " " << l + x << " " << l << endl;
            return;
        }
    }
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
