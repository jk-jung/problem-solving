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

ll n;

ll calc(map<ll, ll> &a, map<ll, ll> &b) {
    if(a.empty()) return 1;
    ll x = a.rbegin()->first - a.begin()->first + 1;
    ll y = b.rbegin()->first - b.begin()->first + 1;
    ll r = x * y;
    if (r < n) r += min(x, y);
    return r;
}

void sub(map<ll, ll> &a, ll x) {
    if (--a[x] == 0)a.erase(x);
}

void solve() {
    cin >> n;
    vector<pair<ll, ll>> v(n);
    map<ll, ll> a, b;
    for (auto &[x, y]: v)cin >> x >> y, a[x]++, b[y]++;

    ll r = calc(a, b);
    for (auto [x, y]: v) {
        sub(a, x);
        sub(b, y);

        r = min(r, calc(a, b));

        a[x]++;
        b[y]++;
    }

    cout << r << endl;
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
