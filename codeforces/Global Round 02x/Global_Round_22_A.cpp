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

ll calc(vi &a, vi &b) {
    ll r = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        if (i < a.size()) r += a[i] * (i < b.size() ? 2 : 1);
        if (i < b.size()) r += b[i] * (i + 1 < a.size() ? 2 : 1);
    }
    return r;
}

void solve() {
    vi a, b;
    int n;
    cin >> n;
    vi t(n);
    for (int &x: t)cin >> x;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (t[i])a.pb(x);
        else b.pb(x);
    }
    sort(a.begin(), a.end()), reverse(a.begin(), a.end());
    sort(b.begin(), b.end()), reverse(b.begin(), b.end());
    cout << max(calc(a, b), calc(b, a)) << endl;
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
