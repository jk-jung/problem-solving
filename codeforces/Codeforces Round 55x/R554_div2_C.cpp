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

ll a, b;

pair<ll, ll> check(ll x) {
    ll k = (a + x - 1) / x * x - a;
    return {(a + k) * (b + k) / gcd(a + k, b + k), k};
}

void solve() {
    // gcd(a + k, b + k) == gcd(b - a, a + k);

    cin >> a >> b;
    if (a > b)swap(a, b);

    ll c = b - a;
    pair<ll, ll> r = {a * b / gcd(a, b), 0};
    for (ll i = 1; i * i <= c; i++) {
        if (c % i)continue;
        ll j = c / i;
        r = min(r, check(i));
        r = min(r, check(j));
    }
    cout << r.S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
