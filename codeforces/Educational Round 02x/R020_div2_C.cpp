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
    ll n, kk;
    cin >> n >> kk;
    if (kk >= 1000000 || kk * (kk + 1) / 2 > n) {
        cout << "-1\n";
        return;
    }
    ll ss = kk * (kk + 1) / 2;
    ll r = -1;
    for (ll k = 1; k * k <= n; k++) {
        if (n % k)continue;
        if (k * ss > n) break;

        ll k2 = n / k;
        r = max(r, k);
        if (k2 <= n / ss && k2 * ss <= n)r = max(r, k2);
    }
    if (r == -1) {
        cout << r << endl;
    } else {
        for (ll i = 1; i < kk; i++) {
            cout << r * i << " ";
            n -= r * i;
        }
        cout << n << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
