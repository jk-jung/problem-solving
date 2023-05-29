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
    int st = 0;
    for (int &x: v) {
        cin >> x;
        st += x;
    }
    if (st % 2) {
        cout << "-1\n";
        return;
    }
    int cnt = abs(st / 2);
    vector<pi> r;
    r.pb({0, 0});
    for (int i = 1; i < n; i++) {
        if (cnt > 0 && st * v[i] > 0 && r.back() == mp(i - 1, i - 1)) {
            cnt--;
            r.pop_back();
            r.pb({i - 1, i});
        } else {
            r.pb({i, i});
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
