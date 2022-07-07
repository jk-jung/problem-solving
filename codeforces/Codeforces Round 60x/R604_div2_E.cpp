#include <string.h>
#include <stdio.h>
#include <math.h>
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

ll mod = 998244353;

ll _pow(ll x, ll y) {
    ll r = 1;
    for (x = x % mod; y; y >>= 1, x = (x * x) % mod)
        if (y & 1) r = (r * x) % mod;
    return r;
}

ll inv(ll x) { return _pow(x, mod - 2); }


void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;

    ll a = 1, b = 0;
    for (int i = 0; i < n; i++) {
        b = (b + _pow(100, n - i) * a) % mod;
        a = a * v[i] % mod;
    }
    cout << b * inv(a) % mod << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
