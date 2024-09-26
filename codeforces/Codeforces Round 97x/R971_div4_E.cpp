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


ll ss(ll a, ll b) {
    return (a + b) * (b - a + 1) / 2;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    ll y = x + n - 1;


    ll s = x, e = y - 1, r = -1;
    while (s <= e) {
        ll m = (s + e) / 2;
        ll diff = ss(x, m) - ss(m + 1, y);
        if (diff < 0)s = m + 1, r = m;
        else e = m - 1;
    }
    ll a = ss(x, r) - ss(r + 1, y);
    ll b = ss(x, r + 1) - ss(r + 2, y);
    cout << min(ab(a), ab(b)) << endl;
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
