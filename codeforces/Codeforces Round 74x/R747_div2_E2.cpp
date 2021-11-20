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

#define mod 1000000007

map<string, int> color = {
        {"white",  0},
        {"yellow", 5},
        {"green",  1},
        {"blue",   4},
        {"red",    2},
        {"orange", 3},
};
map<ll, int> can;
map<pair<ll, int>, ll> ck;

ll pow_(ll x, ll y) {
    ll r = 1;
    for (x = x % mod; y; y >>= 1, x = (x * x) % mod)
        if (y & 1) r = (r * x) % mod;
    return r;
}

ll go(ll x, int c = -1) {
    pair<ll, int> key = {x, c};
    if (ck.count(key)) return ck[key];
    ll r = 0;

    int s = 0, e = 5;
    if (can[x] != -1) s = e = can[x];

    for (int i = s; i <= e; i++) {
        if (c + i == 5 || i == c)continue;

        ll cl = can.count(x * 2) ? go(x * 2, i) : 1;
        ll cr = can.count(x * 2 + 1) ? go(x * 2 + 1, i) : 1;

        r = (r + cl * cr % mod) % mod;
    }
    return ck[key] = r;
}

void solve() {
    int k, n;
    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        ll x;
        string c;
        cin >> x >> c;
        can[x] = color[c];

        while (x > 1) {
            x /= 2;
            if (!can.count(x)) can[x] = -1;
        }
    }

    if (!can.count(1)) can[1] = -1;
    ll r = go(1);
    ll t = pow_(4ll, (1ll << k) - 1 - (ll)can.size());

    cout << r * t % mod << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
