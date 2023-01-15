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
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    if (n * b >= k)cout << -1 << endl;
    else {
        ll s = 0, e = n, r = 0;
        while (s <= e) {
            ll m = (s + e) / 2;
            if (a * m + b * (n - m) >= k)e = m - 1;
            else s = m + 1, r = m;
        }
        cout << r << endl;
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
