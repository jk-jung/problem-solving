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


map<ll, int> f(ll x) {
    map<ll, int> r;
    for (ll i = 2; i * i <= x; i++)
        while (x % i == 0) {
            x /= i;
            r[i]++;
        }
    if (x != 1)r[x]++;
    return r;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a % b) {
        cout << a << endl;
    } else {
        ll r = 1, m1 = 1ll << 60, m2 = 1;
        map<ll, ll> t;
        auto ck = f(b);
        for (auto [x, y]: ck) {
            ll m = 1, mm = 1;
            while (--y)mm *= x;
            while (a % x == 0)a /= x, m *= x;
            t[x] = m;

            ll dif = m / mm;
            if (dif < m1) {
                m1 = dif;
                m2 = x;
            }
        }
        for (auto [x, y]: ck) {
            if (x == m2) {
                for (int i = 1; i < y; i++)r *= x;
            } else {
                r *= t[x];
            }
        }
        cout << r * a << endl;
    }
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
