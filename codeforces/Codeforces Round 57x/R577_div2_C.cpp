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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    sort(v.begin(), v.end());
    v.pb(1ll << 60);

    for (ll i = n / 2, cnt = 1; i < n; i++, cnt++) {
        ll dif = v[i + 1] - v[i];
        ll t = min(dif, k / cnt);
        v[n / 2] += t;
        k -= t * cnt;
    }
    cout << v[n / 2] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
