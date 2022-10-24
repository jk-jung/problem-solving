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
    vi v(n);
    vector<pi> r;
    for (int &x: v)cin >> x;

    int t = 0;
    for (int i = 1; i < n; i++)
        if (v[0] % 2 == v[i] % 2) {
            t = i;
        }

    for (int i = 0; i < t; i++)if (v[t] % 2 == v[i] % 2)r.pb({i, t});
    for (int i = 1; i < n; i++) {
        if (v[i] % 2 != v[0] % 2) {
            r.pb({i - 1, i});
        }
    }
    cout << r.size() << endl;
    for (auto [x, y]: r)cout << x + 1 << " " << y + 1 << endl;
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
