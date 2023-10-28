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
    ll n, m;
    cin >> n >> m;
    m = min(m, n);

    ll s = m, e = n, r = -1;
    while (s <= e) {
        ll mm = (s + e) / 2;

        ll t = mm - m;
        ll cnt = t * (t - 1) / 2 + mm;
        if (t > 0 && t - 1 > (ll)2e18 / t)cnt = n;

        if (cnt >= n) {
            r = mm;
            e = mm - 1;
        } else {
            s = mm + 1;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
