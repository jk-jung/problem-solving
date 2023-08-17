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
    int last = 60;
    vi r;
    ll offset = 0;
    if (n <= (1ll << 30)) {
        n *= (1ll << 30);
        offset = 30;
    }

    for (int i = 0; i < k; i++) {
        int cc = __builtin_popcountll(n);
        int lll = __builtin_ctzll(n);
        if (r.size() && cc == 1 && lll <= last) {

            int t = __builtin_ctzll(n);
            for (; i < k; i++) {
                if (i + 1 == k)r.pb(t);
                else r.pb(--t);
            }
            break;
        }
        int rr = -1;
        for (int t = last; t >= 0; t--) {
            if ((1ll << t) > n)continue;
            ll x = n - (1ll << t), cnt = 0;
            for (int j = 0; j <= 60; j++) {
                if (x >> j & 1) {
                    x -= 1ll << j;
                    if (j >= t) cnt += (1ll << (j - t));
                    else cnt++;
                }
            }
            if (x == 0 && cnt < k - i) {
                rr = t;
                if (r.size())break;
            }
        }
        if (rr != -1) {
            r.pb(rr);
            n -= 1ll << rr;
            last = rr;
        } else {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    for (int x: r)cout << x - offset << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
