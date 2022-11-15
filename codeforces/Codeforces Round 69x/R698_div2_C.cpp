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
    vector<ll> a(n * 2), b(n), d(n);
    for (ll &x: a)cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (a[i * 2] != a[i * 2 + 1]) {
            cout << "NO\n";
            return;
        }
        b[i] = a[i * 2];
    }

    for (int i = 1; i < n; i++) {
        ll dif = b[i - 1] - b[i];
        ll t = 2 * (n - i);
        if (dif == 0 || dif % t) {
            cout << "NO\n";
            return;
        }
        d[i] = dif / t;
    }
    for (int i = 1; i < n; i++)b[n - 1] -= 2 * i * d[i];
    if (b[n - 1] <= 0 || b[n - 1] % (2 * n)) cout << "NO\n";
    else cout << "YES\n";
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
