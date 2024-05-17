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

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    sort(v.begin(), v.end());

    ll s = v.back(), e = 1ll << 60, r = -1;
    while (s <= e) {
        ll m = (s + e) / 2;
        ll t = 0;
        for (ll x: v) {
            t += (m - x);
            if (t >= m)break;
        }
        if (t >= m) {
            r = m;
            e = m - 1;
        } else s = m + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}