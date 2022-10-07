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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    sort(v.begin(), v.end());
    ll r = -(1ll << 60);
    for (int k = 0; k <= 5; k++) {
        ll t = 1;
        for (int i = 0; i < k; i++) t *= v[i];
        for (int i = n - 1; i >= n - 5 + k; i--) t *= v[i];
        r = max(r, t);
    }
    cout << r << endl;
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
