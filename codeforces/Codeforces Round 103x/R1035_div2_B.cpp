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

ll n;

pair<ll, ll> calc(vector<ll> &v) {
    if (n == 1)return mp(v[0], v[0]);
    sort(v.begin(), v.end());
    ll r = 0;
    for (ll x: v)r += x;
    if (v.back() * 2 <= r)return mp(0, r);
    return mp(r - v.back() * 2, r);
}

void solve() {
    ll ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    ll dis = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    vector<ll> v(n);
    for (ll &x: v)cin >> x;

    pair<ll, ll> r = calc(v);
    cout << (r.F * r.F <= dis && dis <= r.S * r.S ? "Yes" : "No") << endl;
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
