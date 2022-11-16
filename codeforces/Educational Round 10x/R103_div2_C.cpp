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
    vi c(n), a(n), b(n);
    vector<ll> d(n);
    for (int &x: c)cin >> x;
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    ll r = 0;
    for (int i = 1; i < n; i++) {
        ll x = min(a[i], b[i]);
        ll y = max(a[i], b[i]);
        d[i] = y - x + 2;
        if(x != y && d[i - 1])
            d[i] = max(d[i], d[i - 1] + x - 1 + c[i - 1] - y + 2);
        r = max(r, d[i] + c[i] - 1);
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
