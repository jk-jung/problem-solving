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
    int n, a, b;
    cin >> n >> a >> b;
    vector<pi> v(n);
    int idx = 0;
    for (auto &[x, y]: v)cin >> x, y = ++idx;
    sort(v.rbegin(), v.rend());

    bool flag = false;
    if (a > b)swap(a, b), flag = true;

    vi r1, r2;
    for (auto &[x, y]: v) {
        ll ca = (ll) (r1.size() + 1) * a * x;
        ll cb = (ll) (r2.size() + 1) * b * x;
        if (ca <= cb) r1.pb(y);
        else r2.pb(y);
    }
    if (flag)swap(r1, r2);
    cout << r1.size() << " ";
    for (int x: r1)cout << x << " ";
    cout << endl;

    cout << r2.size() << " ";
    for (int x: r2)cout << x << " ";
    cout << endl;
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
