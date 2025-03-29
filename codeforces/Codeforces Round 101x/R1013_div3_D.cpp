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
    ll n, m, k;
    cin >> n >> m >> k;
    ll s = 1, e = m, r = -1;
    while (s <= e) {
        ll mid = (s + e) / 2;
        ll row = m / (mid + 1) * mid + m % (mid + 1);
        ll cnt = row * n;

        if (cnt >= k)r = mid, e = mid - 1;
        else s = mid + 1;
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
