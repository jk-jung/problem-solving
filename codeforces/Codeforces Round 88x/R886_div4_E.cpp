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
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n);
    ll b = 0;
    for (ll &x: v) {
        cin >> x;
        c -= x * x;
        b += x * 2;
    }
    ll s = 1, e = 1ll << 60, r;
    while (s <= e) {
        ll x = (s + e) / 2;
        if (n > c / x)e = x - 1;
        else {
            ll t = n * x + b;
            if (t > c / x)e = x - 1;
            else {
                t = x * t;
                if (t > c)e = x - 1;
                else s = x + 1, r = x;
            }
        }
    }
    cout << r / 2 << endl;
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
