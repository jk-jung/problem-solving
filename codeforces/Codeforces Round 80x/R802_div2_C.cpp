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
    // 5 2 7 0 9 => 4
    // 5 2 7 => 9
    // 3 0 5 => 2
    // 5 => 3
    // 0 => 15
    int n, m = (1 << 30);
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, m = min(m, x);
    ll r = 0, op = 0;
    for (int i = 1; i < n; i++) {
        ll k = ab(v[i] - v[i - 1]);
        if (v[i] > v[i - 1]) op += k;
        r += k;
    }
    cout << r + ab(v[n - 1] - op) << endl;
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
