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
    vector<ll> v(n), s(n + 1), idx(n + 1), ss(n);
    for (ll &x: v)cin >> x;

    ll r = 0, a, b;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        t += v[i];
        if (i >= k - 1) {
            idx[i] = i - k + 2;
            ss[i] = s[i] = t;
            t -= v[i - k + 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            s[i] = s[i + 1];
            idx[i] = idx[i + 1];
        }
    }
    for (int i = k - 1; i < n - k; i++) {
        if (ss[i] + s[i + k] > r) {
            r = ss[i] + s[i + k];
            a = i - k + 2;
            b = idx[i + k];
        }
    }
    cout << a << " " << b << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
