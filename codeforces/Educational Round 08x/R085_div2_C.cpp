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
    vector<ll> a(n), b(n), s(n), c(n);
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];

    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll d = i == 0 ? b[n - 1] : b[i - 1];
        c[i] = max(0ll, a[i] - d);
        tot += c[i];
    }
    ll r = 1ll << 60;
    for (int i = 0; i < n; i++) {
        r = min(r, tot - c[i] + a[i]);
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
