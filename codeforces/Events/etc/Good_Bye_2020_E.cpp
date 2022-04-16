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

const ll mod = 1000000007;

ll xx[66][66];

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n), cnt(66);
    for (ll &x: v)cin >> x;

    memset(xx, 0, sizeof(xx));
    for (ll x: v) {
        for (int i = 0; i < 60; i++)if (x >> i & 1)cnt[i]++;
    }


    for (ll x: v) {
        for (int i = 0; i < 60; i++) {
            if (x >> i & 1) {
                for (int j = 0; j < 60; j++) {
                    ll cc = (x >> j & 1) ? n : cnt[j];
                    xx[i][j] += cnt[i] * cc;

                }
            }
        }
    }
    ll r = 0;
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < 60; j++) {
            ll v1 = (1ll << i) % mod;
            ll v2 = (1ll << j) % mod;
            ll c1 = xx[i][j] % mod;
            r = (r + v1 * v2 % mod * c1 % mod) % mod;
        }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
