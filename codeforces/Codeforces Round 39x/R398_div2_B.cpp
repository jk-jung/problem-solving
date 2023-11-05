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
    ll s, e, t;
    cin >> s >> e >> t;
    int n;
    cin >> n;
    vector<ll> v(n), q;
    for (ll &x: v) {
        cin >> x;
        if (x - 1 >= 0 && x - 1 <= e - t)q.pb(x - 1);
        if (x >= 0 && x <= e - t)q.pb(x);
    }
    ll last = s;
    for (ll x: v) {
        x = max(last, x);
        last = x + t;
        if (last >= 0 && last <= e - t)q.pb(last);
    }
    q.pb(0);
    q.pb(s);
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());

    ll r = -1, rt = 1ll << 60, pos = 0, remain = s, bx = 0;
    for (ll x: q) {
        remain -= max(0ll, (x - bx));
        while (pos < v.size() && v[pos] == x)remain += t, pos++;
        if (x + remain + t > e)break;
        if (remain < rt) {
            rt = remain;
            r = x;
        }
        bx = x;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
