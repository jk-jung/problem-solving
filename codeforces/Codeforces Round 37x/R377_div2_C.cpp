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

ll a, b, c;
ll r = a + b + c;

ll f(ll x, ll y, ll z) {
    x -= a;
    y -= b;
    z -= c;
    if (x < 0 || y < 0 || z < 0)return r;
    return x + y + z;
}

void solve() {
    cin >> a >> b >> c;

    ll m = max(a, max(b, c));

    r = 1ll << 62;
    for (int i = 0; i <= 2; i++) {
        ll x = m + i;
        r = min(r, f(x, x, x));
        r = min(r, f(x, x, x - 1));
        r = min(r, f(x, x - 1, x - 1));
        r = min(r, f(x - 1, x, x));
        r = min(r, f(x - 1, x - 1, x));
        r = min(r, f(x - 1, x, x - 1));
        r = min(r, f(x - 1, x - 1, x - 1));
        r = min(r, f(x - 1, x - 2, x - 1));
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
