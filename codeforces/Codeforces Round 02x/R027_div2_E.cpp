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

ll d[1005][1005];
vi v;
ll MAX = 1000000000000000000ll;

bool is_prime(ll x) {
    for (ll i = 2; i * i <= x; i++)if (x % i == 0)return false;
    return true;
}

ll go(ll n, ll k) {
    if (n == 1)return 1;

    ll &r = d[n][k];
    if (r != -1) return r;

    r = MAX;
    for (ll cnt = 2, val = 1; val <= MAX / v[k]; cnt++) {
        val *= v[k];
        if (n % cnt == 0) {
            ll t = go(n / cnt, k + 1);
            if (t <= MAX / val)r = min(r, t * val);
        }
    }

    return r;
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 2; i < 200; i++)if (is_prime(i))v.pb(i);
    memset(d, -1, sizeof(d));
    cout << go(n, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
