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
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    char a = v[0][1], b = v[1][0];
    char c = v[n - 1][n - 2], d = v[n - 2][n - 1];

    vector<pi> r;
    if (a == b) {
        if (c == a) r.pb({n, n - 1});
        if (d == a) r.pb({n - 1, n});
    } else if (c == d) {
        if (a == c) r.pb({1, 2});
        if (b == c) r.pb({2, 1});
    } else {
        r.pb({2, 1});
        if (c == a) r.pb({n, n - 1});
        if (d == a) r.pb({n - 1, n});
    }
    cout << r.size() << endl;
    for (auto [y, x]: r)cout << y << " " << x << endl;
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
