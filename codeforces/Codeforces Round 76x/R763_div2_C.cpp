#include <string.h>
#include <stdio.h>
#include <math.h>
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
    vector<ll> v(n);
    for (ll &x: v)cin >> x;

    int s = 1, e = 1 << 30, r = 1;
    while (s <= e) {
        vector<ll> q = v;
        int m = (s + e) / 2;

        bool ok = true;
        for (int i = n - 1; i >= 2; i--) {
            if (q[i] < m) {
                ok = false;
                break;
            }
            ll need = min(v[i], (q[i] - m)) / 3;
            q[i - 1] += need;
            q[i - 2] += need + need;
        }
        if (q[0] < m) ok = false;
        if (q[1] < m) ok = false;

        if (ok)r = m, s = m + 1;
        else e = m - 1;
    }
    cout << r << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
