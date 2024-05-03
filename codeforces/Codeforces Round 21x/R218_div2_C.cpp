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
    string s;
    ll a, b, c;
    ll x, y, z;
    ll n;
    cin >> s >> a >> b >> c >> x >> y >> z >> n;
    ll v0 = 0, v1 = 1ll << 50, r = 0;
    while (v0 <= v1) {
        ll m = (v0 + v1) / 2;
        ll A = 0, B = 0, C = 0;
        for (char k: s) {
            if (k == 'B')A += m;
            if (k == 'S')B += m;
            if (k == 'C')C += m;
        }
        ll cost = (max(0ll, A - a) * x + max(0ll, B - b) * y + max(0ll, C - c) * z);
        if (cost <= n) {
            r = m;
            v0 = m + 1;
        } else {
            v1 = m - 1;
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
