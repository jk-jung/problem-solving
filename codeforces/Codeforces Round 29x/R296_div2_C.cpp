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


void process(map<ll, ll> &c, map<ll, ll> &d, ll x) {
    auto it = c.lower_bound(x);
    ll r = it->F;
    ll l = prev(it)->F;
    d[r - l]--;
    if (!d[r - l]) d.erase(r - l);
    d[r - x]++;
    d[x - l]++;
    c[x] = 1;
}

void solve() {
    ll w, h, n;
    cin >> w >> h >> n;
    map<ll, ll> a, b, as, bs;
    a[0] = a[w] = 1;
    as[w] = 1;
    b[0] = b[h] = 1;
    bs[h] = 1;
    while (n--) {
        string op;
        ll x;
        cin >> op >> x;
        if (op == "V") process(a, as, x);
        else process(b, bs, x);

        cout << as.rbegin()->F * bs.rbegin()->F << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
