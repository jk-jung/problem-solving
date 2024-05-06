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
    ll a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;

    ll s = 0, e = 1ll << 50, r = -1;
    while (s <= e) {
        ll m = (s + e) / 2;
        ll tot = x * m;
        ll cnt = 0;
        if(tot > b) {
            tot -= (b + 1);
            cnt = 1 + tot / w;
        }

        if (a - cnt >= c - m)r = m, e = m - 1;
        else s = m + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
