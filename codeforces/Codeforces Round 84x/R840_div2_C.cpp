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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    if (n == 2) cout << max({2 * ab(v[0] - v[1]), v[0] + v[1]});
    else if (n == 3)
        cout << max({3 * (ab(v[0] - v[1])), 3 * (ab(v[2] - v[1])), 3 * v[0], 3 * v[2], v[0] + v[1] + v[2]});
    else {
        ll m = 0;
        for (ll x: v)m = max(m, x);
        cout << n * m;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
