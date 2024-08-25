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

void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    vector<ll> s(n);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    int r1 = 0, r2 = 0;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        t += v[i];
        s[i] = t;

        ll a = 0, b = i, r = -1;
        while (a <= b) {
            int m = (a + b) / 2;
            ll len = i - m + 1;
            ll ss = m == 0 ? s[i] : s[i] - s[m - 1];
            ll need = len * v[i] - ss;
            if (need <= k) {
                b = m - 1;
                r = len;
            } else {
                a = m + 1;
            }
        }
        if (r > r1) {
            r1 = r;
            r2 = v[i];
        }
    }
    cout << r1 << " " << r2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
