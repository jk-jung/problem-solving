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

int n, m;

ll f(ll a, ll b, ll c) {
    ll r = ab(a - b) * (m - 1);
    r += ab(a - c) * (n - 1);
    return r + max(ab(a - b), ab(a - c)) * (n - 1) * (m - 1);
}

void solve() {
    cin >> n >> m;
    vi v(n * m);
    for (int &x: v)cin >> x;
    sort(v.begin(), v.end());

    vector<ll> r;
    int t = n * m - 1;
    r.pb(f(v[0], v[t], v[t - 1]));
    r.pb(f(v[0], v[t - 1], v[t]));
    r.pb(f(v[t], v[0], v[1]));
    r.pb(f(v[t], v[1], v[0]));
    sort(r.begin(), r.end());
    cout << r.back() << endl;

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
