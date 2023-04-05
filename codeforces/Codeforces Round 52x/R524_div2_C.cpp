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

pair<ll, ll> f(ll x1, ll y1, ll x2, ll y2) {
    ll x = x2 - x1 + 1;
    ll y = y2 - y1 + 1;
    if (x <= 0 || y <= 0)return {0, 0};
    ll r = x * y;
    if ((x1 + y1) % 2 == 0) {
        return {(r + 1) / 2, r / 2};
    } else {
        return {r / 2, (r + 1) / 2};
    }
}

void solve() {
    ll n, m;
    ll x1, x2, x3, x4;
    ll y1, y2, y3, y4;
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    x1--, x2--, x3--, x4--;
    y1--, y2--, y3--, y4--;

    ll t = n * m;
    vector<ll> r = {(t + 1) / 2, t / 2};
    pair<ll, ll> r1 = f(x1, y1, x2, y2);
    pair<ll, ll> r2 = f(x3, y3, x4, y4);

    ll x5 = max(x1, x3), y5 = max(y1, y3);
    ll x6 = min(x2, x4), y6 = min(y2, y4);

    pair<ll, ll> r3 = f(x5, y5, x6, y6);

    r[0] += r1.S;
    r[1] -= r1.S;

    r[0] -= r2.F;
    r[1] += r2.F;

    r[0] -= r3.S;
    r[1] += r3.S;

    cout << r[0] << " " << r[1] << endl;
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
