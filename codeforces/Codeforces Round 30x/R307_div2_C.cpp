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
    int n, mm;
    cin >> n >> mm;
    vi v(n);
    for (int &x: v)cin >> x;
    while (!v.empty() && v.back() == 0)v.pop_back();
    n = v.size();
    ll s = n + 1, e = 1ll << 50, r = 0;
    while (s <= e) {
        ll m = (s + e) / 2;
        bool ok = true;

        vi w = v;
        ll remain = m;
        ll cur = mm;
        for (ll i = 0; i < n; i++) {
            remain--;
            ll need = (w[i] + remain - 1) / remain;
            if (need > cur) {
                ok = false;
                break;
            }
            cur -= need;
            ll t = need * remain - w[i];
            for (ll j = i + 1; j < n; j++) {
                t--;
                if (t <= 0)break;
                ll k = min(t, (ll)w[j]);
                t -= k;
                w[j] -= k;
            }
        }

        if (ok)e = m - 1, r = m;
        else s = m + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
