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
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll s = 0;
    for (ll &x: v)cin >> x, s += x;

    if (n <= 2)cout << -1 << endl;
    else {
        sort(v.begin(), v.end());
        ll target = v[n / 2] * n * 2;
        cout << max(0ll, target - s + 1) << endl;
    }


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
