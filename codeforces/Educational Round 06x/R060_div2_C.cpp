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
    ll a, b, c, d, n;
    string s;
    cin >> a >> b >> c >> d >> n >> s;
    ll x = (c - a), y = (d - b);
    ll dx = 0, dy = 0;
    for (char t: s) {
        if (t == 'U') dy++;
        if (t == 'D') dy--;
        if (t == 'R') dx++;
        if (t == 'L') dx--;
    }

    ll r = 1ll << 47;
    for (int i = 0, sx = 0, sy = 0; i < n; i++) {
        char t = s[i];
        if (t == 'U') sy++;
        if (t == 'D') sy--;
        if (t == 'R') sx++;
        if (t == 'L') sx--;

        ll ss = 0, ee = 1LL << 47, rr = 1ll << 47;
        while (ss <= ee) {
            ll mm = (ss + ee) / 2;

            ll px = sx + mm * dx;
            ll py = sy + mm * dy;
            ll cnt = mm * n + i + 1;
            if (ab(x - px) + ab(y - py) <= cnt) ee = mm - 1, rr = cnt;
            else ss = mm + 1;
        }
        r = min(r, rr);
    }
    if (r == (1ll << 47))r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
