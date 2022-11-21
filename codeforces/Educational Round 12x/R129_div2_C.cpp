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
    vi c(n), d(n);
    vector<pi> a(n), b;
    for (int i = 0; i < n; i++)cin >> a[i].F, c[i] = a[i].F;
    for (int i = 0; i < n; i++)cin >> a[i].S, d[i] = a[i].S;
    vector<pi> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                r.pb({j + 1, j + 2});
                swap(a[j], a[j + 1]);
            }
        }
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++)b.pb({c[i], d[i]});

    if (a != b) {
        cout << -1 << endl;
    } else {
        cout << r.size() << endl;
        for (auto [x, y]: r)cout << x << " " << y << '\n';
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
