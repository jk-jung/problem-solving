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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    ll m = b * k;
    ll mm = m + (k - 1) * n;
    if (m <= s && s <= mm) {
        for (int i = 0; i < n; i++) {
            ll x = min(s, (i == 0 ? m : 0) + k - 1);
            cout << x << " ";
            s -= x;
        }
        cout << endl;
    } else cout << -1 << endl;
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
