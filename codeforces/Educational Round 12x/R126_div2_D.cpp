#include <string.h>
#include <stdio.h>
#include <math.h>
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

ll n, k;

ll can( vector<ll> v) {
    vector<ll> out(n);
    ll cur = 0, size = 0, tot = 0;
    for (ll i = n - 1; i >= 0; i--) {
        ll need = (max(0ll, v[i] - cur) + k - 1) / k;
        if (i <= k - 1)need = 0;
        v[i] = max(0ll, v[i] - cur - need * k);

        cur += k * need;
        size += need;
        cur -= size;
        tot += need;
        if (need) out[i - k + 1] += need;
        size -= out[i];
    }

    ll t = 0;
    for (int i = 0; i < k; i++) {
        t = max(t, (v[i] + i) / (i + 1));
    }
    tot += t;
    return tot;
}

void solve() {

    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;

    ll r = can(v);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
