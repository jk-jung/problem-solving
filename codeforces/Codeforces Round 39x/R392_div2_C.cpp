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
    ll n, m, k, x, y;
    cin >> n >> m >> k >> y >> x;
    ll t = n * m + max(0ll, n - 2) * m;
    ll cnt = k / t;
    k %= t;
    ll r1 = cnt;
    ll r2 = cnt + (k >= n * m);
    if (cnt && n > 2) {
        r1 *= 2;
        if (k > m)r1++;
        if (k > n * m)r1++;
    } else {
        if (k)r1++;
        if (k > n * m)r1++;
    }

    ll r3 = cnt;
    if (y != 1 && y != n && n > 2) {
        r3 *= 2;
        ll cc = (y - 1) * m + x;
        ll c2 = n * m + x + (n - 1 - y) * m;
        if (k >= cc)r3++;
        if (k >= c2)r3++;
    } else {
        if (k >= (y - 1) * m + x)r3++;
    }
    cout << r1 << " " << r2 << " " << r3 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
