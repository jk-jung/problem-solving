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

ll f(ll k, ll x) {
    if (k > x) return x * (x + 1) / 2 + k - x;
    return (x + (x - k + 1)) * k / 2;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll s = 1, e = m, r = -1;
    while (s <= e) {
        ll x = (s + e) / 2;
        ll k2 = n - k + 1;
        ll t = f(k, x) + f(k2, x) - x;
        if (t <= m) {
            s = x + 1;
            r = x;
        } else e = x - 1;

    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
