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
    int n, q;
    cin >> n >> q;

    vi v(n), st(n);
    for (int &x: v)cin >> x;

    auto f = [&](int i) {
        if (i < 0 || i >= n)return;
        int x = i == 0 ? 0 : v[i - 1];
        int y = v[i];
        int z = i == n - 1 ? 0 : v[i + 1];
        st[i] = 0;
        if (x < y && y > z) st[i] = 1;
        if (x > y && y < z) st[i] = -1;
    };

    for (int i = 0; i < n; i++) {
        f(i);
    }
    ll r = 0;
    for (int i = 0; i < n; i++) {
        r += v[i] * st[i];
    }
    cout << r << endl;

    while (q--) {
        int a, b;
        cin >> a >> b;
        set<int> t;
        a--, b--;
        t.insert(a);
        t.insert(b);
        if (a - 1 >= 0)t.insert(a - 1);
        if (b - 1 >= 0)t.insert(b - 1);
        if (a + 1 < n)t.insert(a + 1);
        if (b + 1 < n)t.insert(b + 1);

        for (int i: t) r -= v[i] * st[i];
        swap(v[a], v[b]);
        for (int i: t) f(i);
        for (int i: t) r += v[i] * st[i];

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
