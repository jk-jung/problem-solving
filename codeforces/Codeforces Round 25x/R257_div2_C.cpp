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



ll check(ll x, ll n, ll m, ll k) {
    ll need = n / x - 1;
    ll res = k - need;
    if (res < 0 || res >= m)return -1;
    ll t = m / (res + 1);
    return x * t;
}

ll process(ll n, ll m, ll k) {
    ll r = -1;
    for (ll i = 1; i * i <= n * 2; i++) {
        r = max(r, check(i, n, m, k));
        r = max(r, check(n / i, n, m, k));
    }
    return r;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    cout << max(process(n, m, k), process(m, n, k));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
