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
    ll n, q;
    cin >> n >> q;
    vector<ll> s(n + 2, 0);
    for (ll i = 1; i <= n; ++i) cin >> s[i];
    ll r = 0;
    for (ll i = 1; i <= n; ++i)
        r += (s[i] != s[i + 1]) * (n - (i + 1) + 1) * i;

    while (q--) {
        ll i, x;
        cin >> i >> x;
        r -= (s[i] != s[i - 1]) * (n - i + 1) * (i - 1);
        r -= (s[i + 1] != s[i]) * (n - (i + 1) + 1) * i;
        s[i] = x;
        r += (s[i] != s[i - 1]) * (n - i + 1) * (i - 1);
        r += (s[i + 1] != s[i]) * (n - (i + 1) + 1) * i;
        cout << r + n * (n + 1) / 2 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
