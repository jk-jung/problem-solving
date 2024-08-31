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

    ll t = sqrt(n);
    for (ll i = max(1ll, t - 1000000); i * i <= n; i++) {
        ll x = i;
        ll rest = n - x * x;
        if (rest % x)continue;
        ll y = rest / x;
        while (x) {
            y -= x % 10;
            x /= 10;
        }
        if (y == 0) {
            cout << i << endl;
            return;
        }
    }

    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
