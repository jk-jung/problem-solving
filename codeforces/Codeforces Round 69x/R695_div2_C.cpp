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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), c(k);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;
    for (ll &x: c)cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<vector<ll>> v = {a, b, c};

    ll r = -(1ll << 60);
    ll ss = 0;
    for (auto &t: v)for (auto x: t)ss += x;
    for (int i = 0; i < 3; i++) {
        ll tmp = ss;
        for (auto x: v[i])tmp -= x * 2;
        r = max(r, tmp);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            r = max(r, ss - (v[i][0] + v[j][0]) * 2);
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
