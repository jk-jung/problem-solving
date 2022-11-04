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
    vi v(n), r(n - 1);
    for (int &x: v)cin >> x;

    ll s = 0, m = ab(v[0] - v[1]);
    for (int i = 0; i < n - 1; i++) {
        ll t = ab(v[i] - v[i + 1]);
        s += t;
        if (i + 2 < n) {
            ll t2 = ab(v[i + 1] - v[i + 2]);
            ll t3 = ab(v[i] - v[i + 2]);
            t = t + t2 - t3;
        }
        m = max(m, t);
    }
    cout << s - m << endl;
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
