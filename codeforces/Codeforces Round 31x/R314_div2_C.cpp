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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    map<ll, ll> a, b;
    for (ll x: v)b[x]++;

    ll r = 0;
    if (k == 1) {
        for (auto [x, y]: b) {
            r += y * (y - 1) * (y - 2) / 6;
        }
    } else {
        ll y = b[0];
        r += y * (y - 1) * (y - 2) / 6;
        for (ll x: v) {
            if (x && x % k == 0 && a.count(x / k) && b.count(x * k))
                r += a[x / k] * b[x * k];
            if (--b[x] == 0)b.erase(x);
            a[x]++;
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
