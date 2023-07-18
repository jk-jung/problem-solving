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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n), s(n);
    for (ll &x: v)cin >> x;
    s[0] = v[0];
    for (int i = 1; i < n; i++)s[i] += s[i - 1] + v[i];

    ll t = 0;
    while (q--) {
        ll x;
        cin >> x;
        t += x;
        if (t >= s.back()) {
            cout << n << '\n';
            t = 0;
        } else {
            int idx = upper_bound(s.begin(), s.end(), t) - s.begin();
            cout << n - idx << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
